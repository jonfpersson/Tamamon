// Tamamon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

#include  "Monster.h"
#include  "UIcontroller.h"

const int windowX = 350;
const int windowY = 300;

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
    sf::RenderWindow window(sf::VideoMode(windowX, windowY), "Tamamon");

    Monster* diggi = new Monster(80, 80, sf::IntRect(0, 0, 25, 25));
    //UIcontroller* uiController = new UIcontroller(&window);
    //uiController->createTextField();

    
    sf::Clock clock;
    
    while (window.isOpen())
    {
        handleEvent(&window);
        diggi->animate(&clock, windowX, windowY);

        window.clear(sf::Color::White);
        window.draw(diggi->getSprite());
        //window.draw(hungerText);
        window.display();
    }

    delete diggi;
//    delete uiController;
    return 0;
}
