#include "UIcontroller.h"
#include <iostream>
#include <stdlib.h>

#define TEXTURE_WIDTH 25

/************************************************
* @brief Constructor
*************************************************/
UIcontroller::UIcontroller() {
    m_font.loadFromFile("arial.ttf");
    vitals = (vitalDisplay*) malloc(sizeof(vitalDisplay) * m_size);

    sf::IntRect inconRect(0, 0, TEXTURE_WIDTH, TEXTURE_WIDTH);
  
    for (int i = 0; i < m_size; i++) {
   
        vitals[i].texture = new sf::Texture();
        vitals[i].sprite = new sf::Sprite();
        vitals[i].textField = new sf::Text("100", m_font);
        
        initTextField(vitals[i].textField, 50 + i * 215, 65);
 
        setSprite(icons[i], vitals[i].texture, &inconRect, vitals[i].sprite, 50 + i * 225, 30, 2);

    }
}

/************************************************
* @brief Destructor
*************************************************/
UIcontroller::~UIcontroller() {
    for (int i = 0; i < m_size; i++) {
        delete (vitals[i]).textField;
        delete (vitals[i]).texture;
        delete (vitals[i]).sprite;
    }

    free(vitals);
}

/************************************************
* @param path - Path to image atlas
* @brief Sets sprite and location of monster
*************************************************/
void UIcontroller::setSprite(const char* path,
    sf::Texture* texture,
    sf::IntRect* rectagleSource,
    sf::Sprite* sprite,
    int x,
    int y,
    int pixelScale) {

    texture->loadFromFile(path);
    sprite->setTexture(*texture);
    sprite->setTextureRect(*rectagleSource);

    sprite->setScale(pixelScale, pixelScale);

    sprite->setOrigin(rectagleSource->width / 2, rectagleSource->height / 2);
    sprite->setPosition(x, y);

}

/************************************************
* @brief Returns ui elements to be drawn
*************************************************/
vitalDisplay** UIcontroller::getElements() {
    return &vitals;
}

/************************************************
* @param x - sideways position of text
* @param y - height position of text
* @brief Initializes text fields
*************************************************/
void UIcontroller::initTextField(sf::Text* obj, int x, int y) {
    obj->setPosition(x, y);
    obj->setCharacterSize(24);
    obj->setFillColor(sf::Color::Black);
}

/************************************************
* @brief Updates all text fields
*************************************************/
void UIcontroller::notifyOfChange(int food, int water, int health) {
 
    sf::Text* f = (vitals[0]).textField;
    sf::Text* w = (vitals[1]).textField;
    sf::Text* h = (vitals[2]).textField;

    f->setString(std::to_string(food));
    w->setString(std::to_string(water));
    h->setString(std::to_string(health));
}