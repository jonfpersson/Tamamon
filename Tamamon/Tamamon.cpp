#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <windows.h>

#include  "Monster.h"
#include  "Button.h"
using namespace std;

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
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);

    sf::RenderWindow window(sf::VideoMode(WINDOWX, WINDOWY), "Tamamon");

    Monster* diggi = new Monster(280, 280, sf::IntRect(0, 0, TEXTURE_WIDTH, TEXTURE_WIDTH), &window);
    Button* FeedBtn = new Button(WINDOWX / 3, 450, "icons\\pizza_button.png", sf::IntRect(0, 0, 43, 33), &window);
    Button* waterBtn = new Button(WINDOWX - (WINDOWX / 3), 450, "icons\\water_button.png", sf::IntRect(0, 0, 43, 33), &window);
    Button* healthBtn = new Button(WINDOWX / 2, 450, "icons\\heart_button.png", sf::IntRect(0, 0, 43, 33), &window);

    sf::Clock clock;
    
    while (window.isOpen())
    {
        window.clear(sf::Color::White);
        handleEvent(&window);
        
        diggi->run(&clock, WINDOWX, WINDOWY);
        
        if (FeedBtn->isClicked(280, 450)) {
            diggi->giveVitalPoint(1, 0, 0);
        }

        if (waterBtn->isClicked(280, 450)) {
            diggi->giveVitalPoint(0, 0, 1);
        }

        if (healthBtn->isClicked(280, 450)) {
            diggi->giveVitalPoint(0, 1, 0);
        }
        
        diggi->draw();
        FeedBtn->draw();
        waterBtn->draw();
        healthBtn->draw();

        window.display();
    }

    delete diggi;
    delete FeedBtn;
    delete waterBtn;
    delete healthBtn;
    return 0;
}
