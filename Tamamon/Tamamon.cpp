// Tamamon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 300), "Tamamon");
    sf::Color white(255, 255, 255);

    sf::Texture texture;
    texture.loadFromFile("C:\\Users\\jonfp\\Downloads\\Koromon_texture_atlas.png");
    sf::IntRect rectagleSource(0, 0, 25, 25);
    
    sf::Sprite sprite(texture, rectagleSource);
    int pixelScale = 5;
    sprite.scale(-pixelScale, pixelScale);
    sprite.setPosition(50, 0);
    
    sf::Clock clock;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (clock.getElapsedTime().asSeconds() > 1.0f) {
            if (rectagleSource.top == 0) {
                rectagleSource.top += 25;
                
                sf::Vector2f position = sprite.getPosition();
                sprite.setPosition(position.x + 2* pixelScale, position.y);
            }
            else
                rectagleSource.top = 0;

            sprite.setTextureRect(rectagleSource);
            clock.restart();
        }

        window.clear(white);
        window.draw(sprite);
        window.display();
    }

    return 0;
}