#include "OPSTACLES.h"
#include <iostream>

Opstacles::Opstacles() {
    velocity = {0.0f, 0.0f};
    texture = sf::Texture();
    texture.loadFromFile("ASSETS/TEXTURES/Opstacle_1.png");
    sprite = sf::Sprite();
    sprite.setTexture(texture);
    sprite.setPosition({700.0f, 500.0f});
}

Opstacles::~Opstacles()
{
    std::cout << "Opstacles destructor\n";
}