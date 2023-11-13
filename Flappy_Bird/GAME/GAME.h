#include <SFML/Graphics.hpp>

#ifndef OOP_GAME_H
#define OOP_GAME_H


class Game {
private:

    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite background;



    void initialize() {
        window.create(sf::VideoMode({800, 600}), "My Window", sf::Style::Default);
        window.setVerticalSyncEnabled(true);
        window.setFramerateLimit(60);
        backgroundTexture.loadFromFile("Assets/Background_fb.png.png");
        background.setTexture(backgroundTexture);
    }

//    void handleEvents() {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//        }
//    }

    void update() {
    }

    void render() {
        window.clear();
        window.display();
    }


public:


    Game();

    ~Game();

//    Game(const Game& other);
//
//    Game& operator=(const Game& other);
//
//    friend std::ostream& operator<<(std::ostream &out, const Game &other);

    void run() {
        while (window.isOpen()) {
            //handleEvents();
            update();
            render();
        }
    }

};

//sf::RenderWindow& getwindow();
//
//sf::Texture& getbackgroundTexture() {
//    return backgroundTexture;
//}
//
//sf::Sprite getbackground() {
//}

#endif //OOP_GAME_H
