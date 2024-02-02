#include "GameObject.h"

std::unique_ptr<Obstacle> ObstacleFactory::createObstacle(ObstacleType type) {
    switch (type) {
        case ObstacleType::Fast:
            return std::make_unique<FastObstacle>();
        case ObstacleType::Slow:
            return std::make_unique<SlowObstacle>();

        default:
            throw std::invalid_argument("Invalid obstacle type");
    }
}


