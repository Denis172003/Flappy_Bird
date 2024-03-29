// GAME.h
#ifndef OOP_GAME_H
#define OOP_GAME_H
#pragma once

#include <SFML/Graphics.hpp>
#include "../OBSTACLES/OBSTACLES.h"
#include "../PLAYER/PLAYER.h"
#include "../Screen/GameOver.h"

class Game {
public:
    static Game& getInstance();
    ~Game();

    void run();
    friend std::ostream& operator<<(std::ostream& out, const Game& game);

private:
    Game();

    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite background;
    sf::Texture whitebgTexture;
    sf::Sprite whitebg;
    Player player;
    Player::Animation animation;
    std::vector<Obstacle*> obstacles;
    GameOver gameOverScreen;
    bool gameOver;

    void spawnFastObstacle();
    void spawnSlowObstacle();
    void handleEvents();
    void handleGameOver();
    void restart();

    static Game* instance;
    static void throwOnTextureLoad(const std::string& textureName, sf::Texture& texture, const std::string& filePath);
};

#endif
