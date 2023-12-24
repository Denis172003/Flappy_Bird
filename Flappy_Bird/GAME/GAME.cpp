#include "GAME.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "../PLAYER/PLAYER.h"
#include "../EXCEPTIONS/EXCEPTIONS.h"

Game::Game() {

    animation = Player::Animation(&player.getTexture(), sf::Vector2u(3, 3), 0.2f);
    window.create(sf::VideoMode({800, 600}), "Flappy Bird", sf::Style::Default);
    window.setTitle("Flappy Bird");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    backgroundTexture.loadFromFile("Assets/Background_fb.png");
    background.setTexture(backgroundTexture);
    gameOver = false;
}

Game::~Game() {
    std::cout << "Game destructor\n";
}

void Game::run() {
    sf::Clock clock, timer;
    sf::Time elapsedTime;

    while (window.isOpen()) {
        try {
            window.clear();
            window.draw(background);

            handleEvents();
            float deltaTime = clock.restart().asSeconds();

            elapsedTime = timer.getElapsedTime();

            if (!player.getHasJumped())
                player.Update(0, 0.0f);
            else
                player.Update(0, deltaTime);
            player.setTextureRect();

            player.update(obstacle, window);
            obstacle.update();

            Position playerPosition = player.getposition().getPosition();
            playerPosition.setX(player.getSprite().getPosition().x);
            playerPosition.setY(player.getSprite().getPosition().y);
            player.setPos(playerPosition);

            if (player.getHasJumped() && elapsedTime.asSeconds() >= 1.0) {
                std::cout << player << std::endl;
                timer.restart();
            }

            window.draw(player.getSprite());
            window.draw(obstacle.getSprite());
            window.display();

        } catch (const BirdCollisionException &e) {
            std::cout << e.what() << std::endl;
            handleGameOver();
        } catch (const BirdOutOfScreenException &e) {
            std::cout << e.what() << std::endl;
            handleGameOver();
        } catch (const GameOverException &e) {
            std::cout << e.what() << std::endl;
            handleGameOver();
        }
    }

    if (gameOver) {
        window.clear();
        gameOverScreen.draw(window);
        window.display();
        sf::sleep(sf::seconds(2));
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

void Game::handleGameOver() {
    gameOver = true;
}