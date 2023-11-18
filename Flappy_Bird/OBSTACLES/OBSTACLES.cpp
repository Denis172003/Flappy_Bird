#include "OBSTACLES.h"
#include <iostream>


Obstacle::Obstacle()
        : texture(),
          sprite(),
          velocity({-1.2f, 0.0f})
{
    texture.loadFromFile("Assets/PIPES.png");
    sprite.setTexture(texture);
    sprite.setPosition({700.0f, -100.0f});
}

Obstacle::~Obstacle()
{
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

Obstacle::Obstacle(const Obstacle& obstacle)= default;



std::ostream& operator<<(std::ostream & out, const Obstacle& obstacle) {
    out << "Velocity X: " << obstacle.velocity.x << "\n" << "Velocity Y: " << obstacle.velocity.y;
    return out;
}


void Obstacle::update(){
    sprite.move(velocity);

    if(sprite.getPosition().x<-1.0f )
        die();
}

void Obstacle::die()
{
    sf::Vector2f startPosition(700.0f, -100.0f);
    sprite.setPosition(startPosition);
}

