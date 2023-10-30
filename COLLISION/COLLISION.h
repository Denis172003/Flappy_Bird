#include <SFML/Graphics.hpp>
#ifndef OOP_COLLISION_H
#define OOP_COLLISION_H


class Collision
{
public:
    Collision();
    ~Collision();

    bool CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2);
    bool CheckSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2);

};


#endif //OOP_COLLISION_H
