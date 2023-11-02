#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include "OPSTACLES/OBSTACLES.h"
#include "GAME/GAME.h"
#include "PLAYER/PLAYER.h"


#ifdef __linux__
#include <X11/Xlib.h>
#endif

int main() {
    #ifdef __linux__
    XInitThreads();
    #endif
    Player player = Player(nullptr, sf::Vector2u(), 0);

    sf::RenderWindow window;
    // NOTE: sync with env variable APP_WINDOW from .github/workflows/cmake.yml:30
    window.create(sf::VideoMode({800, 600}), "My Window", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);


    sf::Texture *playertexture;
   // playertexture->loadFromFile("ASSETS/TEXTURES/Animation_Bird.png");
   // player.getplayertexture(reinterpret_cast<sf::Texture *>(&playertexture));


    Animation animation(playertexture, sf::Vector2u(3,9), 0.3f);

    float deltatime= 0.0f;
    sf::Clock clock;

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("ASSETS/TEXTURES/Background_fb.png.png");
    sf::Sprite background(backgroundTexture);

    Obstacle obstacle = Obstacle(10.0f, 10.0f);


    while(window.isOpen()) {
        sf::Event e;
        while(window.pollEvent(e)) {
            switch(e.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                std::cout << "New width: " << window.getSize().x << '\n'
                          << "New height: " << window.getSize().y << '\n';
                break;
            case sf::Event::KeyPressed:
                std::cout << "Received key " << (e.key.code == sf::Keyboard::X ? "X" : "(other)") << "\n";
                break;
            default:
                break;
            }
        }


        player.update();
        obstacle.update();


        window.clear();

        window.draw(background);
        window.draw(player.getSprite());
        window.draw(obstacle.getSprite());

        window.display();

    }

    return 0;
}
