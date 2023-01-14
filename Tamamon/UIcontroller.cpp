#include "UIcontroller.h"

/************************************************
* @brief Constructor
*************************************************/
UIcontroller::UIcontroller() {
    font.loadFromFile("arial.ttf");

    foodTextField = initTextField(20, 10);
    healthTextField = initTextField(150, 10);
    waterTextField = initTextField(280, 10);

}

/************************************************
* @brief Destructor
*************************************************/
UIcontroller::~UIcontroller() {
    delete foodTextField;
    delete healthTextField;
    delete waterTextField;
}

/************************************************
* @brief Returns ui elements to be drawn
*************************************************/
sf::Text** UIcontroller::getElements() {
    sf::Text** fields = new sf::Text*[3];
    fields[0] = foodTextField;
    fields[1] = healthTextField;
    fields[2] = waterTextField;
    
    return fields;

}

/************************************************
* @param x - sideways position of text
* @param y - height position of text
* @brief Initializes text fields
*************************************************/
sf::Text* UIcontroller::initTextField(int x, int y) {
    sf::Text* obj = new sf::Text("Test", font);
    obj->setPosition(x, y);
    obj->setCharacterSize(24);
    obj->setFillColor(sf::Color::Black);

    return obj;
}