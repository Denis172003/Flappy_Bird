#include "GAME.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "../EXCEPTIONS/EXCEPTIONS.h"

const int NUM_OBSTACLES = 4;
const float FAST_OBSTACLE_SPAWN_INTERVAL = 10.0f;
const float FAST_OBSTACLE_DELETE_INTERVAL = 15.0f;
const float SLOW_OBSTACLE_SPAWN_INTERVAL = 5.0f;
const float SLOW_OBSTACLE_DELETE_INTERVAL = 10.0f;

Game::Game()
        : window(sf::VideoMode(GameSettings::getInstance()->getScreenWidth(), 600), "Flappy Bird", sf::Style::Default),
          backgroundTexture(),
          background(),
          whitebgTexture(),
          whitebg(),
          player(),
          animation(&player.getTexture(), sf::Vector2u(3, 3), 0.2f),
          obstacles(),
          gameOverScreen(),
          settings(GameSettings::getInstance()),
          gameOver(false) {
    window.setTitle("Flappy Bird");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    throwOnTextureLoad("Background", backgroundTexture, "Assets/Background_fb.png");
    background.setTexture(backgroundTexture);

    throwOnTextureLoad("White Background", whitebgTexture, "Assets/WhiteBGLowOp.png");
    whitebg.setTexture(whitebgTexture);
}

Game::~Game() {
    std::cout << "Game destructor\n";
}


void Game::run() {
    sf::Clock clock, timer, fastObstacleTimer, slowObstacleTimer;
    sf::Time elapsedTime1, elapsedTimeFastObstacle, elapsedTimeSlowObstacle;

    try {
        while (window.isOpen()) {
            window.clear();
            window.draw(background);

            handleEvents();

            float deltaTime = clock.restart().asSeconds();
            elapsedTime1 = timer.getElapsedTime();

            if (!player.getHasJumped()) {
                player.Update(0, 0.0f);
            } else {
                player.Update(0, deltaTime);
            }
            player.setTextureRect();

            if (obstacles.empty()) {
                for (int i = 0; i < NUM_OBSTACLES; i++) {
                    auto* obstacle = new Obstacle();
                    obstacles.push_back(obstacle);
                }
            }

            elapsedTimeFastObstacle = fastObstacleTimer.getElapsedTime();
            elapsedTimeSlowObstacle = slowObstacleTimer.getElapsedTime();
            if (elapsedTimeFastObstacle.asSeconds() >= FAST_OBSTACLE_SPAWN_INTERVAL) {
                spawnFastObstacle();
                fastObstacleTimer.restart();
            }

            if (elapsedTimeSlowObstacle.asSeconds() >= SLOW_OBSTACLE_SPAWN_INTERVAL) {
                spawnSlowObstacle();
                slowObstacleTimer.restart();
            }

            for (auto& obstacle : obstacles) {
                obstacle->update();
                window.draw(obstacle->getSprite());
                player.checkcollision(*obstacle);
                player.update(obstacle, deltaTime);
            }

            Position playerPosition = player.getposition().getPosition();
            playerPosition.setX(player.getSprite().getPosition().x);
            playerPosition.setY(player.getSprite().getPosition().y);
            player.setPos(playerPosition);

            if (player.getHasJumped() && elapsedTime1.asSeconds() >= 1.0) {
                std::cout << player << std::endl;
                timer.restart();
            }

            window.draw(player.getSprite());
            window.display();
        }
    } catch (const BirdCollisionException& e) {
        std::cerr << "Bird collision exception: " << e.what() << std::endl;
        handleGameOver();
    } catch (const GameOverException& e) {
        std::cerr << "Game over exception: " << e.what() << std::endl;
        handleGameOver();
    } catch (const WindowClosedException& e) {
        std::cerr << "Window closed exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception during game loop: " << e.what() << std::endl;
        handleGameOver();
    }
}


void Game::throwOnTextureLoad(const std::string& textureName, sf::Texture& texture, const std::string& filePath) {
    if (!texture.loadFromFile(filePath)) {
        throw FlappyBirdException("Failed to load " + textureName + " texture");
    }
}

void Game::spawnFastObstacle() {
    static sf::Clock fastObstacleTimer;

    try {
        sf::Time elapsedTimeFastObstacle = fastObstacleTimer.getElapsedTime();
        if (obstacles.empty()) {
            for (int i = 0; i < NUM_OBSTACLES; i++) {
                auto *obstacle = new Obstacle();
                obstacles.push_back(obstacle);
            }
        }
        if (elapsedTimeFastObstacle.asSeconds() >= FAST_OBSTACLE_DELETE_INTERVAL) {
            if (obstacles.back()->getSprite().getPosition().x < 800.0f) {
                auto *fastObstacle = new FastObstacle();
                obstacles.push_back(fastObstacle);
                fastObstacleTimer.restart();
            }
        }
    } catch (const ObstacleTextureLoadException& e) {
        std::cerr << "Obstacle texture load exception: " << e.what() << std::endl;
    } catch (const ObstacleInvalidPositionException& e) {
        std::cerr << "Obstacle invalid position exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception during fast obstacle spawn: " << e.what() << std::endl;
        handleGameOver();
    }
}

void Game::spawnSlowObstacle() {
    static sf::Clock slowObstacleTimer;

    try {
        sf::Time elapsedTimeSlowObstacle = slowObstacleTimer.getElapsedTime();
        if (obstacles.empty()) {
            for (int i = 0; i < NUM_OBSTACLES; i++) {
                auto *obstacle = new Obstacle();
                obstacles.push_back(obstacle);
            }
        }
        if (elapsedTimeSlowObstacle.asSeconds() >= SLOW_OBSTACLE_DELETE_INTERVAL) {
            if (obstacles.back()->getSprite().getPosition().x < 800.0f) {

                auto *slowObstacle = new SlowObstacle();
                obstacles.push_back(slowObstacle);
                slowObstacleTimer.restart();
            }
        }
    } catch (const ObstacleTextureLoadException& e) {
        std::cerr << "Obstacle texture load exception: " << e.what() << std::endl;
    } catch (const ObstacleInvalidPositionException& e) {
        std::cerr << "Obstacle invalid position exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception during slow obstacle spawn: " << e.what() << std::endl;
        handleGameOver();
    }
}



void Game::handleEvents() {
    sf::Event e = sf::Event();
    while (window.pollEvent(e)) {
        try {
            switch (e.type) {
                case sf::Event::Closed:
                    throw WindowClosedException();
                case sf::Event::Resized:
                    std::cout  << "New width: " << window.getSize().x << '\n'
                              << "New height: " << window.getSize().y << '\n';
                    break;
                case sf::Event::KeyPressed:
                    if (e.key.code == sf::Keyboard::Space || e.key.code == sf::Keyboard::R) {
                        if (gameOver) {
                            restart();
                        }
                    }
                    break;
                default:
                    break;
            }
        } catch (const FlappyBirdException& e1) {
            std::cerr << "Exception during event handling: " << e1.what() << std::endl;
            handleGameOver();
        }
    }
}

std::ostream& operator<<(std::ostream& out, const Game& game) {
    out << "Window size: " << game.window.getSize().x << "x" << game.window.getSize().y << "\n";
    return out;
}

void Game::handleGameOver() {
    gameOver = true;

    sf::Clock timer1;
    sf::Time elapsedTime;
    bool whitebgDrawn = false;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        elapsedTime = timer1.getElapsedTime();
        float sec = elapsedTime.asSeconds();

        if (sec < 0.3f && !whitebgDrawn) {
            window.draw(whitebg);
            whitebgDrawn = true;
        }

        sf::sleep(sf::seconds(0.1f));

        if (sec >= 0.3f) {
            gameOverScreen.draw(window);
        }

        window.display();

        if (sec >= 0.3f) {
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

    throwOnTextureLoad("Background", backgroundTexture, "Assets/Background_fb.png");
    background.setTexture(backgroundTexture);

    gameOver = false;

    for (auto& obstacle : obstacles) {
        delete obstacle;
    }

    obstacles.clear();
}
