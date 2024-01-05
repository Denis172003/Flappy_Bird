#ifndef OOP_OBSTACLES_H
#define OOP_OBSTACLES_H

#pragma once
#include <SFML/Graphics.hpp>
#include <stdexcept>

class Obstacle {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f velocity;

public:
    Obstacle();
    ~Obstacle();
    Obstacle& operator=(const Obstacle& obstacle);
    Obstacle(const Obstacle& obstacle) = default;
    friend std::ostream& operator<<(std::ostream& out, const Obstacle& obstacle);

    void update();
    void die();
    void setPosition(float x, float y);

    const sf::Sprite& getSprite() const { return sprite; }

};

class ObstacleTextureLoadException : public std::runtime_error {
public:
    explicit ObstacleTextureLoadException(const std::string& message)
            : std::runtime_error(message) {}
};

class ObstacleInvalidPositionException : public std::runtime_error {
public:
    explicit ObstacleInvalidPositionException(const std::string& message)
            : std::runtime_error(message) {}
};

#endif // OOP_OBSTACLES_H
