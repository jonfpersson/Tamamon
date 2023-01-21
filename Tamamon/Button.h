#pragma once
#include <SFML/Graphics.hpp>

class Button
{
private:
    sf::Texture m_texture;
    sf::IntRect m_rectagleSource;
    sf::Sprite  m_sprite;

    sf::RenderWindow* window;
    bool wasPressed = false;
    bool isPressed = false;

public:
    void draw();
    const bool isClicked(const float, const float);
    Button(int, int, const char*, sf::IntRect, sf::RenderWindow*);
    ~Button();

};