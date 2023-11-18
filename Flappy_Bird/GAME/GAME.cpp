#include "GAME.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "../OBSTACLES/OBSTACLES.h"
#include "../PLAYER/PLAYER.h"
#include "../COLLISION/COLLISION.h"

Game::Game() {

    animation = Player::Animation(&player.getTexture(), sf::Vector2u(3, 3), 0.2f);
    window.create(sf::VideoMode({800, 600}), "Flappy Bird", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    backgroundTexture.loadFromFile("Assets/Background_fb.png.png");
    background.setTexture(backgroundTexture);
}

Game::~Game() {
    std::cout << "Game destructor\n";
}

void Game::run() {
    sf::Clock clock, timer;
    sf::Time elapsedTime;

    while (window.isOpen()) {
        handleEvents();
        float deltaTime = clock.restart().asSeconds();

        elapsedTime = timer.getElapsedTime();

        if (!player.getHasJumped())
            player.Update(0, 0.0f);
        else
            player.Update(0, deltaTime);
        player.setTextureRect();

        player.update();
        obstacle.update();

        Position playerPosition = player.getposition().getPosition();
        playerPosition.setX(player.getSprite().getPosition().x);
        playerPosition.setY(player.getSprite().getPosition().y);
        player.setPos(playerPosition);

        if (player.getHasJumped() && elapsedTime.asSeconds() >= 1.0) {
            std::cout << player << std::endl;
            timer.restart();
        }


        window.clear();
        window.draw(background);
        window.draw(player.getSprite());
        window.draw(obstacle.getSprite());
        window.display();
    }
}

void Game::handleEvents() {
    sf::Event e = sf::Event();
    while (window.pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                std::cout << "New width: " << window.getSize().x << '\n'
                          << "New height: " << window.getSize().y << '\n';
                break;
            case sf::Event::KeyPressed:
                std::cout << "Received key " << (e.key.code == sf::Keyboard::X ? "X" : "(other)") << "\n";
                break;
            default:
                break;
        }
    }
}

std::ostream &operator<<(std::ostream &out, const Game &game) {
    out << "Window size: " << game.window.getSize().x << "x" << game.window.getSize().y << "\n";
    return out;
}