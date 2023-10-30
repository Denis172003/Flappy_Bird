#include "OBSTACLES.h"
#include <iostream>


Obstacle::Obstacle(float  upperHeight, float playerSpace) {
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