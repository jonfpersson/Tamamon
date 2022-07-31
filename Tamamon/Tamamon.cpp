// Tamamon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
#include  "Monster.h"

int windowX = 350;
int windowY = 300;
int movementSpeed = 2;


void handleEvent(sf::RenderWindow* window) {

    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

void animateMonster(Monster* monster, sf::Clock* clock) {
    
    if (clock->getElapsedTime().asSeconds() > 0.85f) {
        if (monster->getIntRect().top == 0) {
            monster->setIntRect(25, 0, 25, 25);

            monster->move(-movementSpeed, 0);

            if (monster->getX() - (monster->getIntRect().width * 2) <= 0 ||
                monster->getX() + (monster->getIntRect().width * 2) >= windowX) {

                movementSpeed = -movementSpeed;
                monster->flipSprite();
            }

        }
        else {
            monster->setIntRect(0, 0, 25, 25);
        }
        

        monster->updateRect();
        clock->restart();
    }
}

int main()
{
    Monster* diggi = new Monster(50, 0, sf::IntRect(0, 0, 25, 25));
    diggi->setSprite("C:\\Users\\jonfp\\Downloads\\Koromon_texture_atlas_2.png");
    
    sf::RenderWindow window(sf::VideoMode(windowX, windowY), "Tamamon");
    sf::Color white(255, 255, 255);
    
    sf::Clock clock;
    
    while (window.isOpen())
    {
        handleEvent(&window);
        animateMonster(diggi, &clock);

        window.clear(white);
        window.draw(diggi->getSprite());
        window.display();
    }

    delete diggi;
    return 0;
}
