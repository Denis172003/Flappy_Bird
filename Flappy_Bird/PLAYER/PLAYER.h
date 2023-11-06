#include <SFML/Graphics.hpp>
#include <cmath>

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

class Animation
{
protected:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;
    sf::IntRect uvRect;
    float totalTime;
    float switchTime;

public:

    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    ~Animation();

public:

//    sf::Vector2u getimageCount() {
//        return imageCount;
//    }
//
//    sf::Vector2u gecurrentImage() {
//        return currentImage;
//    }
//
//    sf::IntRect getuvRect(){
//        return uvRect;
//    }
//
//
//    float gettotalTime(){
//        return totalTime;
//    }
//
//    float getswitchTime(){
//        return switchTime;
//    }


    void Update(int row, float deltatime);
    void updateUvRect(const sf::Texture* texture_);

};

class Player: public Animation {
private:

    bool hasJumped = false;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f velocity;
    const float GRAVITY = 1.0f;
    const float MAX_FALL_SPEED = 4.0f;
    const float JUMP_SPEED = 8.0f;


public:
    Player();
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

    bool getHasJumped() const {
        return hasJumped;
    }

    sf::Texture& getTexture() {
        return texture;
    }

    void setTexture(const sf::Texture& newTexture) {
        texture = newTexture;
        sprite.setTexture(newTexture);
    }

    sf::Sprite getSprite() { return sprite; }
};




#endif //OOP_PLAYER_H
