#include <SFML/Graphics.hpp>

#ifndef OOP_OPSTACLES_H
#define OOP_OPSTACLES_H


class Opstacles {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f velocity;
public:
    Opstacles();
    ~Opstacles();
    Opstacles& operator=(const Opstacles& opstacle);
    Opstacles(const Opstacles& opstacle);
    friend std::ostream& operator<<(std::ostream & out, const Opstacles& opstacle);


    sf::Sprite getSprite() { return sprite; }
};


#endif //OOP_OPSTACLES_H
