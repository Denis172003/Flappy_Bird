#pragma once

#include <SFML/Graphics.hpp>
#include "../OBSTACLES/OBSTACLES.h"

#ifndef OOP_COLLISION_H
#define OOP_COLLISION_H

class Collision {
    public:

    static void checkPlayerCollision(const sf::Sprite &playerSprite);

    static void checkObstacleCollision(const sf::Sprite &playerSprite, const Obstacle &obstacle);
};


#endif //OOP_COLLISION_H