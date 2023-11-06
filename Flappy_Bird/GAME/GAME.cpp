#include "GAME.h"
#include <iostream>

Game::Game() {
    initialize();
}

Game::~Game() {

    std::cout << "Game destructor\n";
}

//Game::Game(const Game& other) {
//}
//
//Game& Game::operator=(const Game& other) {
//
//}

//void initialize() {
//    window.create(sf::VideoMode({800, 600}), "My Window", sf::Style::Default);
//    window.setVerticalSyncEnabled(true);
//    window.setFramerateLimit(60);
//    backgroundTexture.loadFromFile("ASSETS/TEXTURES/Background_fb.png.png");
//    background.setTexture(backgroundTexture);
//}

