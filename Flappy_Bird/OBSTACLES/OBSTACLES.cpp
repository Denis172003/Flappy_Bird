
#include "OBSTACLES.h"
#include <iostream>

Obstacle::Obstacle()
        : texture(),
          sprite(),
          velocity({-2.5f, 0.0f}) {
    texture.loadFromFile("Assets/PIPES.png");
    sprite.setTexture(texture);
    sprite.setPosition({0.0f, 0.0f});
}

Obstacle::~Obstacle() {
    std::cout << "Obstacle destructor\n";
}

Obstacle& Obstacle::operator=(const Obstacle& obstacle) {
    if (this != &obstacle) {
        texture = obstacle.texture;
        sprite = obstacle.sprite;
        velocity = obstacle.velocity;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Obstacle& obstacle) {
    out << "Velocity X: " << obstacle.velocity.x << "\n"
        << "Velocity Y: " << obstacle.velocity.y;
    return out;
}

void Obstacle::update() {
    sprite.move(velocity);

    if (sprite.getPosition().x < -100.0f)
        die();
}

void Obstacle::die() {
    sf::Vector2f startPosition(800.0f, -100.0f);
    sprite.setPosition(startPosition);
}

void Obstacle::setPosition(float x, float y) {
    sprite.setPosition(sf::Vector2f(x, y));
}