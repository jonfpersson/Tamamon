// Tamamon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include  "Monster.h"

void handleEvent(sf::RenderWindow* window) {

    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

int main()
{
    Monster* diggi = new Monster(50, 0, sf::IntRect(0, 0, 25, 25));
    diggi->setSprite("C:\\Users\\jonfp\\Downloads\\Koromon_texture_atlas_2.png");
    
    sf::RenderWindow window(sf::VideoMode(500, 300), "Tamamon");
    sf::Color white(255, 255, 255);
    
    sf::Clock clock;
    
    while (window.isOpen())
    {
        handleEvent(&window);

        if (clock.getElapsedTime().asSeconds() > 1.0f) {
            if (diggi->getIntRect().top == 0) {
                diggi->setIntRect(25, 0, 25, 25);
                
                sf::Vector2f position = diggi->getSprite().getPosition();
                diggi->move(5, 0);
            }
            else
                diggi->setIntRect(0, 0, 25, 25);

            diggi->updateRect();
            clock.restart();
        }

        window.clear(white);
        window.draw(diggi->getSprite());
        window.display();
    }

    return 0;
}
