#include <iostream>
#include "GameOver.h"

GameOver::GameOver() {
    init();
}

GameOver::~GameOver() {
    std::cout << "GameOver destructor\n";
}

void GameOver::init() {
    if (!font.loadFromFile("path/to/your/font.ttf")) {
        std::cout << "Error loading font\n";
    }

    gameOverText.setFont(font);
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(50);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(200.0f, 250.0f);

}

void GameOver::draw(sf::RenderWindow& window) {
    window.draw(gameOverText);
}
