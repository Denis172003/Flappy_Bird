#pragma once
#include <iostream>
#include "GameOver.h"

GameOver::GameOver() {
    init();
}

GameOver::~GameOver() {
    std::cout << "GameOver destructor\n";
}

void GameOver::init() {
    if (!texture.loadFromFile("Assets/Game_Over_bg.png")) {
        std::cout << "Error loading texture\n";
    }

    sprite.setTexture(texture);
    sprite.setPosition({175.0f, 100.0f});
}

void GameOver::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
