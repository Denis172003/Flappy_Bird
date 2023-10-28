#include <SFML/Graphics.hpp>

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H


class PLAYER {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f velocity;
    int *chestie;
public:
    PLAYER();
    ~PLAYER();
    PLAYER& operator=(const PLAYER& player);
    PLAYER(const PLAYER& player);
    friend std::ostream& operator<<(std::ostream & out, const PLAYER& player);

    void update();
    void handleKeys();
    void handleGravity();
    void jump();

    sf::Sprite getSprite() { return sprite; }
};


#endif //OOP_PLAYER_H
