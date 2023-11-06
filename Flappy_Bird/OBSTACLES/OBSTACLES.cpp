#include "OBSTACLES.h"
#include <iostream>

//float  upperHeight, float playerSpace

Obstacle::Obstacle() {
    velocity = {-1.2f, 0.0f};
    texture = sf::Texture();
    texture.loadFromFile("ASSETS/TEXTURES/Pipes.png");
    sprite = sf::Sprite();
    sprite.setTexture(texture);
    sprite.setPosition({700.0f, -100.0f});

}

Obstacle::~Obstacle()
{
    std::cout << "Obstacle destructor\n";
}

Obstacle& Obstacle::operator=(const Obstacle& obstacle) {
    if (this == &obstacle) {
        return *this;
    }

    texture = obstacle.texture;
    sprite = obstacle.sprite;
    velocity = obstacle.velocity;

    return *this;
}

Obstacle::Obstacle(const Obstacle& obstacle) {

    texture = obstacle.texture;
    sprite = obstacle.sprite;
    velocity = obstacle.velocity;
}

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