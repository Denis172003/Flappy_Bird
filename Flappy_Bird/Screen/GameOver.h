
#ifndef OOP_GAMEOVER_H
#define OOP_GAMEOVER_H


#pragma once

#include <SFML/Graphics.hpp>

class GameOver {
private:
    sf::Font font;
    sf::Text gameOverText;

public:
    GameOver();
    ~GameOver();

    void init();
    void draw(sf::RenderWindow& window);
};

#endif //OOP_GAMEOVER_H
