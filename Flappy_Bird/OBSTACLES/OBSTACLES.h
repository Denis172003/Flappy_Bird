#include <SFML/Graphics.hpp>

#ifndef OOP_OBSTACLES_H
#define OOP_OBSTACLES_H

//enum class ObstacleType {
//    Pipe_Up,
//    Pipe_Down,
//};

class Obstacle {
private:
    //ObstacleType type;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f velocity;
    //float gapY;
    //float gapHeight;
public:
    //float upperHeight, float playerSpace

    Obstacle();
    ~Obstacle();
    Obstacle& operator=(const Obstacle& obstacle);
    Obstacle(const Obstacle& obstacle);
    friend std::ostream& operator<<(std::ostream & out, const Obstacle& obstacle);

    void update();
    void die();

    sf::Texture getTexture() { return texture; }
    sf::Sprite getSprite() { return sprite; }
};


#endif //OOP_OBSTACLES_H
