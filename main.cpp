#include <SFML/Graphics.hpp>

#include "froggy.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(840, 840), "SFML works!");

    sf::Texture background_texture;
    sf::Sprite background_sprite;

    background_texture.loadFromFile("background.png");
    background_sprite.setTexture(background_texture);

    froggy frog("froggy.png");

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

        window.clear();
        window.draw(background_sprite);
        frog.draw(window);
        window.display();
    }

    return 0;
}