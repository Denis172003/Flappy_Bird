#include "COLLISION.h"
#include "../EXCEPTIONS/EXCEPTIONS.h"

bool showHitboxes = false;

void Collision::checkPlayerCollision(const sf::Sprite& playerSprite, sf::RenderWindow& window) {

    sf::FloatRect birdBounds = playerSprite.getGlobalBounds();

    float stateWidth = birdBounds.width / 3 - 57;
    float stateHeight = birdBounds.height / 3 - 80;

    sf::FloatRect realBirdBounds(birdBounds.left + 29, birdBounds.top + 40, stateWidth, stateHeight);

    if (showHitboxes) {
        sf::RectangleShape birdBox(sf::Vector2f(realBirdBounds.width, realBirdBounds.height));
        birdBox.setPosition(realBirdBounds.left, realBirdBounds.top);
        birdBox.setFillColor(sf::Color::Transparent);
        birdBox.setOutlineColor(sf::Color::Red);
        birdBox.setOutlineThickness(1.0f);

        window.draw(birdBox);
    }
}

void Collision::checkObstacleCollision(const sf::Sprite& playerSprite, const Obstacle& obstacle, sf::RenderWindow& window,sf::Event& e) {
    sf::FloatRect birdBounds = playerSprite.getGlobalBounds();

    float stateWidth = birdBounds.width / 3 - 57;
    float stateHeight = birdBounds.height / 3 - 80;

    sf::FloatRect realBirdBounds(birdBounds.left + 29, birdBounds.top + 40, stateWidth, stateHeight);

    sf::FloatRect upperObstacleBounds(obstacle.getSprite().getPosition().x, obstacle.getSprite().getPosition().y,
                                      obstacle.getSprite().getGlobalBounds().width - 2,
                                      obstacle.getSprite().getGlobalBounds().height / 2 - 72);

    sf::FloatRect lowerObstacleBounds(obstacle.getSprite().getPosition().x,
                                      obstacle.getSprite().getPosition().y + obstacle.getSprite().getGlobalBounds().height / 2 + 72,
                                      obstacle.getSprite().getGlobalBounds().width - 2,
                                      obstacle.getSprite().getGlobalBounds().height / 2);

    if (showHitboxes) {
        sf::RectangleShape upperObstacleBox(sf::Vector2f(upperObstacleBounds.width, upperObstacleBounds.height));
        upperObstacleBox.setPosition(upperObstacleBounds.left, upperObstacleBounds.top);
        upperObstacleBox.setFillColor(sf::Color::Transparent);
        upperObstacleBox.setOutlineColor(sf::Color::Red);
        upperObstacleBox.setOutlineThickness(1.0f);

        sf::RectangleShape lowerObstacleBox(sf::Vector2f(lowerObstacleBounds.width, lowerObstacleBounds.height));
        lowerObstacleBox.setPosition(lowerObstacleBounds.left, lowerObstacleBounds.top);
        lowerObstacleBox.setFillColor(sf::Color::Transparent);
        lowerObstacleBox.setOutlineColor(sf::Color::Red);
        lowerObstacleBox.setOutlineThickness(1.0f);

        window.draw(upperObstacleBox);
        window.draw(lowerObstacleBox);
    }

    updateHitboxDisplay(e);

    if (realBirdBounds.intersects(upperObstacleBounds) || realBirdBounds.intersects(lowerObstacleBounds)) {
        if (!showHitboxes) {
            throw BirdCollisionException();
        }
    }
}

void Collision::updateHitboxDisplay(sf::Event& e) {
    if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::H) {
        showHitboxes = !showHitboxes;
    }
}
