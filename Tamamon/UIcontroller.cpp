#include "UIcontroller.h"

/************************************************
* @brief Constructor
*************************************************/
UIcontroller::UIcontroller() {
    m_font.loadFromFile("arial.ttf");

    m_foodTextField = initTextField(20, 10);
    m_healthTextField = initTextField(150, 10);
    m_waterTextField = initTextField(280, 10);

}

/************************************************
* @brief Destructor
*************************************************/
UIcontroller::~UIcontroller() {
    delete m_foodTextField;
    delete m_healthTextField;
    delete m_waterTextField;
}

/************************************************
* @brief Returns ui elements to be drawn
*************************************************/
sf::Text** UIcontroller::getElements() {
    sf::Text** fields = new sf::Text*[3];
    fields[0] = m_foodTextField;
    fields[1] = m_healthTextField;
    fields[2] = m_waterTextField;
    
    return fields;

}

/************************************************
* @param x - sideways position of text
* @param y - height position of text
* @brief Initializes text fields
*************************************************/
sf::Text* UIcontroller::initTextField(int x, int y) {
    sf::Text* obj = new sf::Text("Test", m_font);
    obj->setPosition(x, y);
    obj->setCharacterSize(24);
    obj->setFillColor(sf::Color::Black);

    return obj;
}