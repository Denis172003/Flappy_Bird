#include <SFML/Graphics.hpp>

#ifndef OOP_OPSTACLES_H
#define OOP_OPSTACLES_H


class Obstacle {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f velocity;
    float gapY;
    float gapHeight;
public:
    Obstacle(float upperHeight, float playerSpace);
    ~Obstacle();
    Obstacle& operator=(const Obstacle& obstacle);
    Obstacle(const Obstacle& opstacle);
    friend std::ostream& operator<<(std::ostream & out, const Obstacle& opstacle);

    void update();
    void die();

    sf::Sprite getSprite() { return sprite; }
};


#endif //OOP_OPSTACLES_H
