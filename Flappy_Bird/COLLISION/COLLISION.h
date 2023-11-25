#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Collision {
private:
    sf::Vector2f position;
    sf::FloatRect bounds;
    bool isActive;

public:
    Collision();
    ~Collision();
    Collision& operator=(const Collision& collision);

    [[maybe_unused]] Collision(const Collision& collision);
    friend std::ostream& operator<<(std::ostream& out, const Collision& collision);

    void update();

    [[nodiscard]] sf::Vector2f getPosition() const { return position; }

    [[maybe_unused]] [[nodiscard]] sf::FloatRect getBounds() const { return bounds; }

    [[maybe_unused]] [[nodiscard]] bool getIsActive() const { return isActive; }

    void setPosition(const sf::Vector2f& newPosition) { position = newPosition; }

    [[maybe_unused]] void setBounds(const sf::FloatRect& newBounds) { bounds = newBounds; }

    [[maybe_unused]] void setIsActive(bool active) { isActive = active; }



};
