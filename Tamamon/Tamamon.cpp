// Tamamon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

#include  "Monster.h"

const int windowX = 350;
const int windowY = 300;
int movementSpeedX = 2;
int movementSpeedY = 1;

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
* @param monster - User's monster
* @param clock - Clock keeping track of time
* @brief Handles animation of monster
*************************************************/
void animateMonster(Monster* monster, sf::Clock* clock) {
    
    if (clock->getElapsedTime().asSeconds() > 0.85f) {
        if (monster->getIntRect().top == 0) {
            monster->setIntRect(25, 0, 25, 25);

            monster->move(-movementSpeedX, movementSpeedY);
            
            /* Prevent from going through edges */
            if (monster->getX() - (monster->getIntRect().width * 2) <= 0 ||
                monster->getX() + (monster->getIntRect().width * 2) >= windowX ||
                (double) rand() / (RAND_MAX) > 0.85) {

                movementSpeedX = -movementSpeedX;
                monster->flipSprite();
            }
            
            /* Changes the y speed at random intervals */
            if ((double) rand() / (RAND_MAX) > 0.7) {
                movementSpeedY = -movementSpeedY;
            }

        }
        else {
            monster->setIntRect(0, 0, 25, 25);
        }
        
        monster->updateRect();
        clock->restart();
    }
}

/************************************************
* @brief Main method
*************************************************/
int main()
{
    Monster* diggi = new Monster(windowX/2, 0, sf::IntRect(0, 0, 25, 25));
    diggi->setSprite("C:\\Users\\jonfp\\Downloads\\Koromon_texture_atlas_2.png");
    
    /*sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text hungerText(std::to_string(diggi->getFoodLevel()), font);
    hungerText.setPosition(windowX / 2, 200);
    hungerText.scale(5, 5);*/

    sf::RenderWindow window(sf::VideoMode(windowX, windowY), "Tamamon");
    sf::Color white(255, 255, 255);
    
    sf::Clock clock;
    
    while (window.isOpen())
    {
        handleEvent(&window);
        animateMonster(diggi, &clock);

        window.clear(white);
        window.draw(diggi->getSprite());
        //window.draw(hungerText);
        window.display();
    }

    delete diggi;
    return 0;
}
