#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
//#include <chrono>
//#include <thread>
#include "./Flappy_Bird/OBSTACLES/OBSTACLES.h"
#include "./Flappy_Bird/GAME/GAME.h"
#include "./Flappy_Bird/PLAYER/PLAYER.h"
#include "./Flappy_Bird/COLLISION/COLLISION.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif

int main() {
    #ifdef __linux__
    XInitThreads();
    #endif

    Collision collision;
    Player player = Player();

    Game game;
    sf::RenderWindow window;
    // NOTE: sync with env variable APP_WINDOW from .GitHub/workflows/cmake.yml:30
    window.create(sf::VideoMode({800, 600}), "My Window", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    sf::Texture playerTexture = player.getTexture();

    Player::Animation animation(&playerTexture, sf::Vector2u(3,3), 2000.0f);
    sf::Clock clock, timer;
    sf::Time elapsedTime;

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile(R"(C:\Users\denis\CLionProjects\Flappy_Birddddddd\Assets\Textures\Background_fb.png)");
    sf::Sprite background(backgroundTexture);

    Obstacle obstacle = Obstacle();

    while (window.isOpen()) {
        sf::Event e = sf::Event();
        while (window.pollEvent(e)) {
            switch (e.type) {
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

        float deltatime = clock.restart().asSeconds();

        elapsedTime = timer.getElapsedTime();

        if (!player.getHasJumped())
            player.Update(0, 0.0f);
        else
            player.Update(0, deltatime);
        player.setTextureRect();

        player.update();
        obstacle.update();

        Position playerPosition = player.getposition().getPosition();
        playerPosition.setX(player.getSprite().getPosition().x);
        playerPosition.setY(player.getSprite().getPosition().y);

        if (player.getHasJumped() && elapsedTime.asSeconds() >= 1.0)
        {
            std::cout << "Player X: " << playerPosition.getX() << std::endl;
            std::cout << "Player Y: " << playerPosition.getY() << std::endl;
            timer.restart();
        }

        window.clear();

        window.draw(background);
        window.draw(player.getSprite());
        window.draw(obstacle.getSprite());

        window.display();
    }

    return 0;
}