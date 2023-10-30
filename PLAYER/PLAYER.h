#include <SFML/Graphics.hpp>
#include <cmath>

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H


class Player {
private:
    float _rotation{};
    bool hasJumped = false;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f velocity;
    const float GRAVITY = 1.0f;
    const float MAX_FALL_SPEED = 4.0f;
    const float JUMP_SPEED = 8.0f;
    const float MAX_TILT_ANGLE_UP = 5.0f;
    const float MAX_TILT_ANGLE_DOWN = -5.0f;


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
