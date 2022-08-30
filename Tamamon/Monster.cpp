#include "Monster.h"
#include <iostream>
using namespace std;

/************************************************
* @param xSteps - Steps to move in x axis
* @param ySteps - Steps to move in y axis
* @brief Moves monster by xSteps and ySteps
*************************************************/
void Monster::move(int xSteps, int ySteps){

	float xOffset = xSteps * m_pixelScale;
	float yOffset = ySteps * m_pixelScale;
	m_sprite.setPosition(m_x + xOffset, m_y + yOffset);
	
	m_x += xOffset;
	m_y += yOffset;

}

/************************************************
* @param clock - Intern clock to keep track of animation
* @param movementSpeedX - Speed of x axis
* @param movementSpeedY - Speed of y axis
* @param windowX - Window x size
* @param windowY - Window y size
* @brief Sets sprite and location of monster
*************************************************/
void Monster::animate(sf::Clock* const clock, 
                      int windowX,
	                  int windowY) {

	if (clock->getElapsedTime().asSeconds() > 0.85f) {
		if (getIntRect().top == 0) {
			setIntRect(25, 0, 25, 25);

			move(-movementSpeedX, movementSpeedY);

			/* Prevent from going through edges */
			if (m_x - (getIntRect().width * 2) <= 0 ||
				m_x + (getIntRect().width * 2) >= windowX ||
				(double)rand() / (RAND_MAX) > 0.85) {

				movementSpeedX = -movementSpeedX;
				flipSprite();
			}

			/* Changes the y speed at random intervals */
			if (m_y <= 0 ||
				m_y + (getIntRect().height * 4) >= windowY) {

				movementSpeedY = -movementSpeedY;
			}
		}
		else {
			setIntRect(0, 0, 25, 25);
		}

		updateAtlas();
		clock->restart();
	}
}

/************************************************
* @param path - Path to image atlas
* @brief Sets sprite and location of monster
*************************************************/
void Monster::setSprite(const char* path) { 
	m_texture.loadFromFile(path);
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(m_rectagleSource);
	
	m_sprite.scale(m_pixelScale, m_pixelScale);
	
	m_sprite.setOrigin(m_rectagleSource.width / 2, 0);

	m_sprite.setPosition(m_x, m_y);
}

/************************************************
* @return Monster's x coordinate
*************************************************/
int Monster::getX() {
	return m_x;
}

/************************************************
* @return Monster's y coordinate
*************************************************/
int Monster::getY() {
	return m_y;
}

/************************************************
* @return Monster's hunger level
*************************************************/
int Monster::getFoodLevel() {
	return m_food;
}

/************************************************
* @return Monster's health points
*************************************************/
int Monster::getHpLevel() {
	return m_hp;
}


/************************************************
* @return Monster's hydration
*************************************************/
int Monster::getWaterLevel() {
	return m_water;
}

/************************************************
* @brief Updates shown part of image atlas 
*************************************************/
void Monster::updateAtlas() {
	m_sprite.setTextureRect(m_rectagleSource);
}

/************************************************
* @return Sprite of monster
*************************************************/
sf::Sprite Monster::getSprite() {
	return m_sprite;
}

/************************************************
* @brief Flips sprite in relation to center
*************************************************/
void Monster::flipSprite() {
	m_sprite.scale(-1, 1);
}

/************************************************
* @return IntRect used by sprite
*************************************************/
sf::IntRect Monster::getIntRect() {
	return m_rectagleSource;
}

/************************************************
* @param top - Top coordinate of rectangle
* @param left - Left coordinate of rectangle
* @param height - Height of rectangle
* @param width - Width of rectangle
* @brief Sets new values to m_rectagleSource
*************************************************/
void Monster::setIntRect(int top, int left, int height, int width) {
	m_rectagleSource.top = top;
	m_rectagleSource.left = left;
	m_rectagleSource.height = height;
	m_rectagleSource.width = width;

}