#include "COLLISION.h"
#include "../EXCEPTIONS/EXCEPTIONS.h"

bool showHitboxes = false;

void Collision::checkPlayerCollision(const sf::Sprite& playerSprite) {
    sf::FloatRect birdBounds = playerSprite.getGlobalBounds();

    float stateWidth = birdBounds.width / 3 - 57;
    float stateHeight = birdBounds.height / 3 - 80;

    (sf::FloatRect(birdBounds.left + 29, birdBounds.top + 40, stateWidth, stateHeight));

}

void Collision::checkObstacleCollision(const sf::Sprite& playerSprite, const Obstacle& obstacle) {
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


    if (realBirdBounds.intersects(upperObstacleBounds) || realBirdBounds.intersects(lowerObstacleBounds)) {
        if (!showHitboxes) {
            throw BirdCollisionException();
        }
    }
}



