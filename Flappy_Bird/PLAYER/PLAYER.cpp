#include "PLAYER.h"
#include <iostream>

Player::Player()
: Animation(nullptr, sf::Vector2u(3, 3), 0.15f), // Modify flap speed
          texture(),
          sprite(),
          velocity({0.0f, 0.0f})
{

    texture.loadFromFile("Assets/Animation_Bird.png");
    sprite.setTexture(texture);
    sprite.setPosition({100.0f, 300.0f});
    updateUvRect(&texture);
    //sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
}

Player::~Player() {
    std::cout << "Player destructor\n";
}

Player& Player::operator=(const Player &player) {
    if (this != &player) {
        texture = player.texture;
        sprite = player.sprite;
        velocity = player.velocity;
    }
    return *this;
}

Player::Player(const Player& player)
: Animation(player), texture(player.texture), sprite(player.sprite), velocity(player.velocity) {
}

std::ostream& operator<<(std::ostream& out, const Player& player) {
    out << "Velocity X: " << player.velocity.x << "\n" << "Velocity Y: " << player.velocity.y<<"\n";
    out << "Player Position: " << player.getposition();
    return out;
}

std::ostream& operator<<(std::ostream& out, const Position& position) {
    out << "(" << position.getX() << ", " << position.getY() << ")";
    return out;
}

void Player::jump() {
    velocity.y = -JUMP_SPEED;

    if (getHasJumped()) {
        getRotation().updateRotation(getVelocity().y);
    }
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
}

void Rotation::updateRotation(float velocity) {
    if (std::abs(velocity) > 6.0f) {
        _rotation = (float)(std::atan(velocity / ROTATION_CONSTANT) * 180.0 / 3.14159265358979323846);
        if (_rotation > MAX_ROTATION) {
            _rotation = MAX_ROTATION;
        }
    }
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

void Player::setPos(Position pos) {
    position.setX(pos.getX());
    position.setY(pos.getY());
}

void Player::update() {
    handleKeys();
    handleGravity();
    checkcollision();
    sprite.move(velocity);
}

void Player::setTextureRect() {
    texture.loadFromFile("Assets/Animation_Bird.png", this->uvRect);
}

void Animation::updateUvRect(const sf::Texture* texture_) {
    if (texture_ == nullptr) return;
    uvRect.width = static_cast<int>(texture_->getSize().x) / static_cast<int>(imageCount.x);
    uvRect.height = static_cast<int>(texture_->getSize().y)/ static_cast<int>(imageCount.y);
}

Animation::Animation() {
    imageCount = {0, 0};
    currentImage = {0, 0};
    totalTime = 0.0f;
    switchTime = 0.0f;
}

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
        : imageCount(imageCount),
          currentImage({0, 0}),
          totalTime(0.0f),
          switchTime(switchTime)
{
    if (texture != nullptr) {
        uvRect.width = static_cast<int>(texture->getSize().x) / static_cast<int>(imageCount.x);
        uvRect.height = static_cast<int>(texture->getSize().y) / static_cast<int>(imageCount.y);
    }
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

    uvRect.left = static_cast<int>(currentImage.x) * static_cast<int>(uvRect.width);
    uvRect.top = static_cast<int>(currentImage.y) * static_cast<int>(uvRect.height);
}
