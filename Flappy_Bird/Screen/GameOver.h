#ifndef GAME_OVER_H
#define GAME_OVER_H

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

#endif // GAME_OVER_H
