#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

#include  "Monster.h"

#define WINDOWX 350
#define WINDOWY 300
#define TEXTURE_WIDTH 25


sf::Text* hungerText = new sf::Text();
sf::Text* hpText = new sf::Text();
sf::Text* waterText = new sf::Text();
/************************************************
* @param window - Window
* @brief Handles closing of window
*************************************************/
void handleEvent(sf::RenderWindow* window) {

    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

/************************************************
* @brief Main method
*************************************************/
int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOWX, WINDOWY), "Tamamon");

    Monster* diggi = new Monster(80, 80, sf::IntRect(0, 0, TEXTURE_WIDTH, TEXTURE_WIDTH));
    
    sf::Clock clock;
    
    while (window.isOpen())
    {
        handleEvent(&window);
        diggi->run(&clock, WINDOWX, WINDOWY);

        window.clear(sf::Color::White);
        window.draw(diggi->getSprite());

        for (int i = 0; i < 3; i++) {
            sf::Text txt = *(diggi->getUIElements()[i]);
            window.draw(txt);
        }

        window.display();
    }

    delete diggi;
    return 0;
}
