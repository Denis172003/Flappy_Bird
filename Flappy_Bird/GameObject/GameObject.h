#ifndef OOP_OBSTACLEFACTORY_H
#define OOP_OBSTACLEFACTORY_H

#include <memory>
#include <stdexcept>
#include "../OBSTACLES/OBSTACLES.h"

enum class ObstacleType {
    Fast,
    Slow
};

class ObstacleFactory {
public:
    static std::unique_ptr<Obstacle> createObstacle(ObstacleType type) {
        switch (type) {
            case ObstacleType::Fast:
                return std::make_unique<FastObstacle>();
            case ObstacleType::Slow:
                return std::make_unique<SlowObstacle>();

            default:
                throw std::invalid_argument("Invalid obstacle type");
        }
    }
};

#endif // OOP_OBSTACLEFACTORY_H
