#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

#include  "Monster.h"
#include  "Button.h"

#define WINDOWX 550
#define WINDOWY 500
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

    Monster* diggi = new Monster(280, 280, sf::IntRect(0, 0, TEXTURE_WIDTH, TEXTURE_WIDTH), &window);
    Button* btn = new Button(sf::IntRect(0, 0, TEXTURE_WIDTH, TEXTURE_WIDTH));
    //sf::Mouse* ms = new sf::Mouse();

    sf::Clock clock;
    
    while (window.isOpen())
    {
        window.clear(sf::Color::White);
        handleEvent(&window);
        
        diggi->run(&clock, WINDOWX, WINDOWY);
      //  btn->isClicked(*ms, 280, 280);
        
        diggi->draw();
        btn->draw(&window);

        window.display();
    }

    delete diggi;
    delete btn;
    return 0;
}
