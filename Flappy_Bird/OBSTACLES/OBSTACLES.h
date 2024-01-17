#ifndef OOP_OBSTACLES_H
#define OOP_OBSTACLES_H

#pragma once
#include <SFML/Graphics.hpp>
#include <stdexcept>



class Obstacle{
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f velocity;

public:
    Obstacle();
    virtual ~Obstacle();
    Obstacle& operator=(const Obstacle& obstacle);
    Obstacle(const Obstacle& obstacle);
    friend std::ostream& operator<<(std::ostream& out, const Obstacle& obstacle);
    Obstacle(Obstacle&&) noexcept;
    Obstacle& operator=(Obstacle&&) noexcept;


    virtual void update();
    virtual void die();
    void setPosition(float x, float y);


    virtual const sf::Sprite& getSprite() const { return sprite; }

};

class FastObstacle: public Obstacle{


public:

    void update()override;
    void die()override;
    const sf::Sprite& getSprite() const override  { return sprite; }

};



#endif // OOP_OBSTACLES_H
