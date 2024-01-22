// OBSTACLES.cpp

#include "OBSTACLES.h"
#include "../EXCEPTIONS/EXCEPTIONS.h"
#include <iostream>
#include <random>

Obstacle::Obstacle()
        : texture(),
          sprite(),
          velocity({-2.5f, 0.0f}) {

    if (!texture.loadFromFile("Assets/PIPES.png")) {
        throw ObstacleTextureLoadException("Failed to load obstacle texture");
    }


    sprite.setTexture(texture);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);



    switch (dis(gen)) {
        case 0:
            sprite.setPosition({800.0f, -150.0f});
            break;
        case 1:
            sprite.setPosition({1600.0f, -200.0f});
            break;
        case 2:
            sprite.setPosition({2200.0f, -80.0f});
            break;
        case 3:
            sprite.setPosition({2900.0f, -10.0f});
            break;
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

void SlowObstacle::update() {

    sprite.move(velocity/2.0f);

    if (sprite.getPosition().x < -100.0f)
        die();
}


void Obstacle::die() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);

    switch (dis(gen)) {
        case 0:
            sprite.setPosition({800.0f, -150.0f});
            break;
        case 1:
            sprite.setPosition({1600.0f, -200.0f});
            break;
        case 2:
            sprite.setPosition({2200.0f, -80.0f});
            break;
        case 3:
            sprite.setPosition({2900.0f, -10.0f});
            break;
    }

}

void FastObstacle::die() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);

    switch (dis(gen)) {
        case 0:
            sprite.setPosition({800.0f, -150.0f});
            break;
        case 1:
            sprite.setPosition({1600.0f, -200.0f});
            break;
        case 2:
            sprite.setPosition({2200.0f, -80.0f});
            break;
        case 3:
            sprite.setPosition({2900.0f, -10.0f});
            break;
    }
}

void SlowObstacle::die() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);

    switch (dis(gen)) {
        case 0:
            sprite.setPosition({800.0f, -150.0f});
            break;
        case 1:
            sprite.setPosition({1600.0f, -200.0f});
            break;
        case 2:
            sprite.setPosition({2200.0f, -80.0f});
            break;
        case 3:
            sprite.setPosition({2900.0f, -10.0f});
            break;
    }
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

