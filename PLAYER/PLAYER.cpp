#include "PLAYER.h"

#include <iostream>

PLAYER::PLAYER() {
    chestie = new int { 15 };
    velocity = {0.0f, 0.0f};
    texture = sf::Texture();
    texture.loadFromFile("ASSETS/TEXTURES/Player.png");
    sprite = sf::Sprite();
    sprite.setTexture(texture);
    sprite.setPosition({400.0f, 300.0f});
}

PLAYER::~PLAYER() {
    std::cout << "Player destructor\n";
    delete chestie;
}

PLAYER& PLAYER::operator=(const PLAYER &player) {
    texture = player.texture;
    sprite = player.sprite;
    velocity = player.velocity;
    chestie = player.chestie;
    return *this;
}

PLAYER::PLAYER(const PLAYER& player) {
    texture = player.texture;
    sprite = player.sprite;
    velocity = player.velocity;
    chestie = player.chestie;
}

std::ostream& operator<<(std::ostream& out, const PLAYER& player) {
    out << "Velocity X: " << player.velocity.x << "\n" << "Velocity Y: " << player.velocity.y;
    return out;
}

void PLAYER::handleKeys() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        jump();
    }
}

void PLAYER::handleGravity() {
    if (velocity.y > 2.0f) return;
    velocity.y += 0.3f;
}

void PLAYER::update() {
    handleKeys();
    handleGravity();

    sprite.move(velocity);
}

void PLAYER::jump() {
    velocity.y = -3.0f;
}