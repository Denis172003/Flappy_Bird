#ifndef OOP_GAME_H
#define OOP_GAME_H

#include <SFML/Graphics.hpp>
#include "../OBSTACLES/OBSTACLES.h"
#include "../PLAYER/PLAYER.h"
#include "../Screen/GameOver.h"

class Game {
public:
    Game();
    ~Game();
    void run();
    friend std::ostream& operator<<(std::ostream& out, const Game& game);

private:
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite background;
    sf::Texture whitebgTexture;
    sf::Sprite whitebg;
    Player player;
    Player::Animation animation;
    Obstacle obstacle1;
    Obstacle obstacle2;
    Obstacle obstacle3;
    Obstacle obstacle4;
    GameOver gameOverScreen;
    bool gameOver;

    void handleEvents();
    void handleGameOver();
    void restart();
};

#endif
