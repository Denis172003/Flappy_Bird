#include <SFML/Graphics.hpp>
#include <cmath>

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H


class Rotation {
private:

    float _rotation;
    const float ROTATION_CONSTANT = 6.0f;
    const float MAX_ROTATION = 8.0f;

public:
    explicit Rotation( float _rotation = 0.0f) {
        this->_rotation = _rotation;
    }


    void updateRotation(float velocity);

};


class Position {
private:
    float x;
    float y;

public:
    explicit Position(float initialX = 0.0f, float initialY = 0.0f) {
        x = initialX;
        y = initialY;
    }
    [[nodiscard]]float getX() const { return x; }
    [[nodiscard]]float getY() const { return y; }

    void setX(float x_) { x = x_; }
    void setY(float y_) { y = y_; }

    Position& getPosition() {
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Position& position);

};


class Animation
{
protected:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;
    sf::IntRect uvRect;
    float totalTime;
    float switchTime;

public:
    Animation();
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    ~Animation();

public:

    void Update(int row, float deltatime);
    void updateUvRect(const sf::Texture* texture_);

};

class Player: public Animation {
private:

    Rotation rotation;
    Position position;
    bool hasJumped = false;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f velocity;
    const float GRAVITY = 1.0f;
    const float MAX_FALL_SPEED = 4.0f;
    const float JUMP_SPEED = 8.0f;


public:
    Player();
    explicit Player(sf::Texture *texture);
    ~Player();
    Player& operator=(const Player& player);
    Player(const Player& player);
    friend std::ostream& operator<<(std::ostream & out, const Player& player);


public:
    void update();
    void handleKeys();
    void handleGravity();
    void jump();
    void die();
    void checkcollision();
    void setTextureRect();
    void setPos(Position pos);

    Rotation& getRotation() {
        return rotation;
    }

    Position getposition() const {
        return position;
    }

    sf::Vector2f getVelocity() const {
        return velocity;
    }

    bool getHasJumped() const {
        return hasJumped;
    }

    sf::Texture& getTexture() {
        return texture;
    }

//    void setTexture(const sf::Texture& newTexture) {
//        texture = newTexture;
//        sprite.setTexture(newTexture);
//    }

    sf::Sprite getSprite() { return sprite; }
};

#endif //OOP_PLAYER_H
