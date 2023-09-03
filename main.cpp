#include <SFML/Graphics.hpp>

#include "froggy.h"
#include "car.h"
#include "log.h"
#include "carManager.h"
#include "logManager.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(840, 840), "froggy");

    sf::Texture background_texture;
    sf::Sprite background_sprite;

    background_texture.loadFromFile("background.png");
    background_sprite.setTexture(background_texture);

    froggy frog("froggy.png");
    carManager cars("car.png");
    logManager logs("log.png");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::Resized)
            {
                window.setSize(sf::Vector2u(840, 840));
            }
            if (event.type == sf::Event::KeyPressed)
            {
                frog.handleButtonPressed(event);
            }
        }

        cars.update();
        logs.update();
        frog.update();

        if (cars.hasCrashed(frog)) { frog.setDead(); }
        if (logs.froggyIsOnLog(frog)) { frog.setOnLog(); }

        window.clear();
        window.draw(background_sprite);
        cars.draw(window);
        logs.draw(window);
        frog.draw(window);
        window.display();
    }

    return 0;
}