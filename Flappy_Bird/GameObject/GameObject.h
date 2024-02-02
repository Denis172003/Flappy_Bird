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
    static std::unique_ptr<Obstacle> createObstacle(ObstacleType type);
};

#endif // OOP_OBSTACLEFACTORY_H

