#include "COLLISION.h"

Collision::Collision()
        : position(0.0f, 0.0f),
          bounds(sf::FloatRect(0.0f, 0.0f, 0.0f, 0.0f)),
          isActive(true) {
}

Collision::~Collision() {
    std::cout << "Collision destructor\n";
}

Collision& Collision::operator=(const Collision& collision) {
    if (this == &collision) {
        return *this;
    }
    position = collision.position;
    bounds = collision.bounds;
    isActive = collision.isActive;

    return *this;
}

[[maybe_unused]] Collision::Collision(const Collision& collision) = default;

std::ostream& operator<<(std::ostream& out, const Collision& collision) {
    out << "Position: (" << collision.position.x << ", " << collision.position.y << ")\n";
    out << "Bounds: (" << collision.bounds.left << ", " << collision.bounds.top << ", " << collision.bounds.width << ", " << collision.bounds.height << ")\n";
    out << "Active: " << (collision.isActive ? "true" : "false") << "\n";
    return out;
}

void Collision::update() {
    bounds.left = position.x;
    bounds.top = position.y;

    if (isActive) {
        bounds.width = 34.0f;
        bounds.height = 24.0f;
    }
    else {
        bounds.width = 0.0f;
        bounds.height = 0.0f;
    }

}
