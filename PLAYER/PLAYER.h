#include <SFML/Graphics.hpp>

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H


class Player {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f velocity;
public:
    Player();
    ~Player();
    Player& operator=(const Player& player);
    Player(const Player& player);
    friend std::ostream& operator<<(std::ostream & out, const Player& player);

    void update();
    void handleKeys();
    void handleGravity();
    void jump();
    void die();
    void checkcollision();

    sf::Sprite getSprite() { return sprite; }
};


#endif //OOP_PLAYER_H
