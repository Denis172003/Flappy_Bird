#include "PLAYER.h"
#include <iostream>

Player::Player() :  Animation(nullptr, sf::Vector2u(3, 3), 0.1f) {
    velocity = {0.0f, 0.0f};
    texture = sf::Texture();
    texture.loadFromFile("ASSETS/TEXTURES/Animation_Bird.png");
    sprite = sf::Sprite();
    sprite.setTexture(texture);
    sprite.setPosition({100.0f, 300.0f});
    updateUvRect(&texture);
    //sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
}

Player::~Player() {
    std::cout << "Player destructor\n";
}

Player& Player::operator=(const Player &player) {
    texture = player.texture;
    sprite = player.sprite;
    velocity = player.velocity;
    return *this;
}

Player::Player(const Player& player) : Animation(player), texture(player.texture), sprite(player.sprite), velocity(player.velocity) {
}



std::ostream& operator<<(std::ostream& out, const Player& player) {
    out << "Velocity X: " << player.velocity.x << "\n" << "Velocity Y: " << player.velocity.y;
    return out;
}

void Player::jump() {
    velocity.y = -JUMP_SPEED;
}

void Player::handleKeys() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        jump();
        hasJumped = true;
    }

}

void Player::handleGravity() {

    if (!hasJumped) {
        velocity.y = 0.0f;
    }
    else {
        velocity.y += GRAVITY;
    }

    if (velocity.y > MAX_FALL_SPEED) {
        velocity.y = MAX_FALL_SPEED;
    }


  /* if (std::abs(velocity.y) > 6.0f) {
        _rotation = static_cast<float>(std::atan(velocity.y / ROTATION_CONSTANT) * 180.0 / M_PI);
        if (_rotation > MAX_ROTATION) {
            _rotation = MAX_ROTATION;
        }
    }


    float oldX = sprite.getPosition().x;


    sprite.setPosition(oldX, sprite.getPosition().y);
    sprite.setRotation(_rotation);

  */
}

void Player::die()
{
    hasJumped = false;
    sf::Vector2f startPosition(100.0f, 300.0f);
    sprite.setPosition(startPosition);
}

void Player::checkcollision() {
    if(sprite.getPosition().y>520.0f || sprite.getPosition().y<-40.0f )
        die();
}

void Player::update() {
    handleKeys();
    handleGravity();
    checkcollision();
    sprite.move(velocity);
}

void Player::setTextureRect() {
    texture.loadFromFile("ASSETS/TEXTURES/Animation_Bird.png", this->uvRect);
}

void Animation::updateUvRect(const sf::Texture* texture_) {
    if (texture_ == nullptr) return;
    uvRect.width = texture_->getSize().x/ float(imageCount.x);
    uvRect.height = texture_->getSize().y/ float(imageCount.y);
}

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime){

    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime =0.0f;
    currentImage.x =0;

    if (texture == nullptr) return;
    uvRect.width = texture->getSize().x/ float(imageCount.x);
    uvRect.height = texture->getSize().y/ float(imageCount.y);
}

Animation::~Animation(){
    std::cout << "Animation destructor\n";
}

void Animation::Update(int row, float deltatime) {

    currentImage.y=row;
    totalTime += deltatime;

    if(totalTime > switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++;
    }

    if(currentImage.x >= imageCount.x)
    {
        currentImage.x =0;
    }

    uvRect.left = currentImage.x * uvRect.width;
    uvRect.top = currentImage.y * uvRect.height;
}

