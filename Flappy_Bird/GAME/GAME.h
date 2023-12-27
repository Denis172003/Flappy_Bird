#ifndef OOP_GAME_H
#define OOP_GAME_H

#include <SFML/Graphics.hpp>
#include "../OBSTACLES/OBSTACLES.h"
#include "../PLAYER/PLAYER.h"
#include "../COLLISION/COLLISION.h"
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
    Player player;
    Player::Animation animation;
    Obstacle obstacle;
    GameOver gameOverScreen;
    bool gameOver;


    void handleEvents();
    void handleGameOver();
    void restart();
};

#endif
