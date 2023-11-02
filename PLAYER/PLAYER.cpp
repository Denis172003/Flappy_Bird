#include "PLAYER.h"
#include <iostream>

#define M_PI 3.14
#define MAX_ROTATION 35.0f
#define ROTATION_CONSTANT 2.0f

Player::Player(sf::Texture texture, sf::Vector2u imageCount, float switchTime) : Animation(&texture, imageCount, switchTime) {
    velocity = {0.0f, 0.0f};
    texture = sf::Texture();
    texture.loadFromFile("ASSETS/TEXTURES/Player.png");
    sprite = sf::Sprite();
    sprite.setTexture(texture);
    sprite.setPosition({100.0f, 300.0f});
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
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

//Player::Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, const Player &player): Animation(texture, imageCount, switchTime) {
//    texture = player.texture;
//    sprite = player.sprite;
//    velocity = player.velocity;
//}

Player::Player(const Player &player){
    this->texture = player.texture;
    this->sprite = player.sprite;
    this->velocity = player.velocity;
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
    if(sprite.getPosition().y>600.0f || sprite.getPosition().y<0.0f )
        die();
}

void Player::update() {
    handleKeys();
    handleGravity();
    checkcollision();
    sprite.move(velocity);
}


Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime){

    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime =0.0f;
    currentImage.x =0;

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