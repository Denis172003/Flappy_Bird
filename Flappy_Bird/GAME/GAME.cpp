
#include "GAME.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "../EXCEPTIONS/EXCEPTIONS.h"

Game::Game()
        : window(sf::VideoMode(800, 600), "Flappy Bird", sf::Style::Default),
          backgroundTexture(),
          background(),
          whitebgTexture(),
          whitebg(),
          player(),
          animation(&player.getTexture(), sf::Vector2u(3, 3), 0.2f),
          obstacle1(),
          obstacle2(),
          obstacle3(),
          obstacle4(),
          gameOverScreen(),
          gameOver(false) {

    window.setTitle("Flappy Bird");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    backgroundTexture.loadFromFile("Assets/Background_fb.png");
    background.setTexture(backgroundTexture);
    whitebgTexture.loadFromFile("Assets/WhiteBGLowOp.png");
    whitebg.setTexture(whitebgTexture);



    //obstacle1.setPosition(700.0f, -100.0f);
    //obstacle2.setPosition(700.0f, -200.0f);
//    obstacle3.setPosition(700.0f, -100.0f);
//    obstacle4.setPosition(700.0f, -100.0f);
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

            if (!player.getHasJumped()) {
                player.Update(0, 0.0f);
            } else {
                player.Update(0, deltaTime);
            }
            player.setTextureRect();
            player.update(obstacle1, window);

            obstacle1.update();
            window.draw(obstacle1.getSprite());
            //player.update(obstacle2, window);

            obstacle2.update();
            window.draw(obstacle2.getSprite());


            obstacle3.update();
            window.draw(obstacle3.getSprite());


            obstacle4.update();
            window.draw(obstacle4.getSprite());


            Position playerPosition = player.getposition().getPosition();
            playerPosition.setX(player.getSprite().getPosition().x);
            playerPosition.setY(player.getSprite().getPosition().y);
            player.setPos(playerPosition);

            if (player.getHasJumped() && elapsedTime.asSeconds() >= 1.0) {
                std::cout << player << std::endl;
                timer.restart();
            }

            window.draw(player.getSprite());
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
                if (e.key.code == sf::Keyboard::Space || e.key.code == sf::Keyboard::R) {
                    if (gameOver) {
                        restart();
                    }
                }
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

    sf::Clock timer;
    bool whitebgDrawn = false;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        float elapsedSeconds = static_cast<float>(timer.getElapsedTime().asSeconds());

        if (elapsedSeconds < 0.3f && !whitebgDrawn) {
            window.draw(whitebg);
            whitebgDrawn = true;
        }

        sf::sleep(sf::seconds(0.1));

        if (elapsedSeconds >= 0.3f) {
            gameOverScreen.draw(window);
        }

        window.display();

        if (elapsedSeconds >= 0.3f) {
            break;
        }
    }

    sf::Event event{};
    while (window.waitEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            break;
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::R) {
                restart();
                break;
            }
        } else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Right) {
                restart();
                break;
            }
        }
    }
}


void Game::restart() {
    window.create(sf::VideoMode({800, 600}), "Flappy Bird", sf::Style::Default);
    window.setTitle("Flappy Bird");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    backgroundTexture.loadFromFile("Assets/Background_fb.png");
    background.setTexture(backgroundTexture);
    gameOver = false;
    obstacle1.die();
    obstacle2.die();
//    obstacle3.die();
//    obstacle4.die();
}

