#include "Button.h"
#include "UIcontroller.h"

using namespace std;

void Button::draw()
{
    window->draw(m_sprite);
    
}

const bool Button::isClicked(const float X, const float Y)
{
    bool mouseIsInside = m_sprite.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);
    if (!mouseIsInside) {
        return false;
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        isPressed = true;
        return false;
    }

    wasPressed = false;
    if (isPressed) {
        wasPressed = isPressed;
        isPressed = false;
    }

    return wasPressed;
    
}

Button::Button(int x, int y, const char* path, sf::IntRect r, sf::RenderWindow* w)
{
    window = w;
    m_rectagleSource = r;

    UIcontroller::setSprite(path, &m_texture, &m_rectagleSource, &m_sprite, x, y, 2);
}

Button::~Button()
{
  
}
