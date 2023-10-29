#include "PLAYER.h"

#include <iostream>

Player::Player() {
    velocity = {0.0f, 0.0f};
    texture = sf::Texture();
    texture.loadFromFile("ASSETS/TEXTURES/Player.png");
    sprite = sf::Sprite();
    sprite.setTexture(texture);
    sprite.setPosition({400.0f, 300.0f});
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
    }
}

void Player::handleGravity() {
    if (velocity.y > 2.0f) return;
    velocity.y += 0.3f;
}

void Player::update() {
    handleKeys();
    handleGravity();
    sprite.move(velocity);
}

void Player::jump() {
    velocity.y = -3.0f;
}