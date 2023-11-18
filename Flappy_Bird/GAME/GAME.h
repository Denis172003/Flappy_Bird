#ifndef OOP_GAME_H
#define OOP_GAME_H

#include <SFML/Graphics.hpp>
#include "../OBSTACLES/OBSTACLES.h"
#include "../PLAYER/PLAYER.h"
#include "../COLLISION/COLLISION.h"

class Game {
public:
    Game();
    ~Game();
    void run();

private:
    sf::RenderWindow window;
    sf::Texture playerTexture;
    Player player;
    Player::Animation animation;
    sf::Texture backgroundTexture;
    sf::Sprite background;
    Obstacle obstacle;

    friend std::ostream& operator<<(std::ostream& out, const Game& game);


    void handleEvents();
};

#endif
