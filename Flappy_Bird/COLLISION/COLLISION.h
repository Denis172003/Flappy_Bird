#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef OOP_COLLISION_H
#define OOP_COLLISION_H

class Collision {
private:
    sf::Vector2f position;
    sf::FloatRect bounds;
    bool isActive;

public:
    Collision();
    ~Collision();

    Collision& operator=(const Collision& collision);
    Collision(const Collision& collision);

    friend std::ostream& operator<<(std::ostream& out, const Collision& collision);

    void update();
    //void handleCollision();


//    sf::Vector2f getPosition() const { return position; }
//    sf::FloatRect getBounds() const { return bounds; }
//   bool getIsActive() const { return isActive; }
//    void setPosition(const sf::Vector2f& newPosition) { position = newPosition; }
//    void setBounds(const sf::FloatRect& newBounds) { bounds = newBounds; }
//    void setIsActive(bool active) { isActive = active; }
};

#endif // OOP_COLLISION_H
