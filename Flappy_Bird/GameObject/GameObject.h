#ifndef OOP_GAMEOBJECT_H
#define OOP_GAMEOBJECT_H

#include <memory>
#include "../PLAYER/PLAYER.h"
#include "../OBSTACLES/OBSTACLES.h"

class GameObject {
public:
    virtual ~GameObject() = default;
};

enum class ObjectType {
    Player,
    Obstacle
};

class ObjectFactory {
public:
    static std::shared_ptr<GameObject> createObjectFactory(ObjectType type) {
        switch (type) {
            case ObjectType::Player:
                return std::shared_ptr<Player>();
            case ObjectType::Obstacle:
                return std::shared_ptr<Obstacle>();
            default:
                return nullptr;
        }
    }
};

#endif //OOP_GAMEOBJECT_H
