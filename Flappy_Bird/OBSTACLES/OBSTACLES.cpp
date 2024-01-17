// OBSTACLES.cpp

#include "OBSTACLES.h"
#include "../EXCEPTIONS/EXCEPTIONS.h"
#include <iostream>

Obstacle::Obstacle()
        : texture(),
          sprite(),
          velocity({-2.5f, 0.0f}) {

    try {
        if (!texture.loadFromFile("Assets/PIPES.png")) {
            throw ObstacleTextureLoadException("Failed to load obstacle texture");
        }

        sprite.setTexture(texture);
        sprite.setPosition({800.0f, -100.0f});

    } catch (const ObstacleTextureLoadException& e) {
        std::cerr << e.what() << std::endl;
    }
}

Obstacle::~Obstacle() {
    std::cout << "Obstacle destructor\n";
}

Obstacle::Obstacle(const Obstacle &obstacle): texture(obstacle.texture), sprite(obstacle.sprite), velocity(obstacle.velocity) {

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



void FastObstacle::update() {

    sprite.move(velocity*30.0f);

    if (sprite.getPosition().x < -100.0f)
        die();
}


void Obstacle::die() {
    sf::Vector2f startPosition(800.0f, -100.0f);
    sprite.setPosition(startPosition);
}

void FastObstacle::die() {

    sf::Vector2f startPosition(800.0f, -100.0f);
    sprite.setPosition(startPosition);
}


void Obstacle::setPosition(float x, float y) {
    if (x < 0.0f || y < 0.0f) {
        throw ObstacleInvalidPositionException("Invalid position for obstacle");
    }

    sprite.setPosition(sf::Vector2f(x, y));
}

Obstacle::Obstacle(Obstacle&& obstacle) noexcept
        : texture(obstacle.texture),
          sprite(std::move(obstacle.sprite)),
          velocity(obstacle.velocity) {
}

Obstacle& Obstacle::operator=(Obstacle&& obstacle) noexcept {
    if (this != &obstacle) {
        texture = obstacle.texture;
        sprite = std::move(obstacle.sprite);
        velocity = obstacle.velocity;
    }
    return *this;
}

