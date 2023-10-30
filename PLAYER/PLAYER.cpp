#include "PLAYER.h"
#include <iostream>

Player::Player() {
    velocity = {0.0f, 0.0f};
    texture = sf::Texture();
    texture.loadFromFile("ASSETS/TEXTURES/Player.png");
    sprite = sf::Sprite();
    sprite.setTexture(texture);
    sprite.setPosition({100.0f, 300.0f});
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

Player::Player(const Player& player) {
    texture = player.texture;
    sprite = player.sprite;
    velocity = player.velocity;
}

std::ostream& operator<<(std::ostream& out, const Player& player) {
    out << "Velocity X: " << player.velocity.x << "\n" << "Velocity Y: " << player.velocity.y;
    return out;
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

void Player::update() {
    handleKeys();
    handleGravity();
    checkcollision();
    sprite.move(velocity);
}

void Player::jump() {
    velocity.y = -JUMP_SPEED;
}

void Player::checkcollision() {
    if(sprite.getPosition().y>550.0f || sprite.getPosition().y<-35.0f )
        die();
}

void Player::die()
{
    hasJumped = false;
    sf::Vector2f startPosition(100.0f, 300.0f);
    sprite.setPosition(startPosition);
}