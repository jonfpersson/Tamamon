#include "Monster.h"
#include <iostream>
using namespace std;

#define EGG_HATCH_TIMER 12


/************************************************
* @brief Constructor
*************************************************/
Monster::Monster(int x, int y, sf::IntRect rs) {
	m_x = x;
	m_y = y;
	m_rectagleSource = rs;
	setSprite("egg_texture_atlas.png");

	uiController = new UIcontroller();
}

/************************************************
* @brief Destructor
*************************************************/
Monster::~Monster() {
	delete uiController;
}

/************************************************
* @brief Main loop
*************************************************/
void Monster::run(sf::Clock* const clock, int windowX, int windowY) {

	if (clock->getElapsedTime().asSeconds() > 0.45f) {

		animate(clock, windowX, windowY);
		clock->restart();
	}
}

/************************************************
* @param clock - Intern clock to keep track of animation
* @param movementSpeedX - Speed of x axis
* @param movementSpeedY - Speed of y axis
* @param windowX - Window x size
* @param windowY - Window y size
* @brief Sets sprite and location of monster
*************************************************/
void Monster::animate(sf::Clock* const clock, int windowX, int windowY) {

	evolveTimer++;

	nextAtlasSquare();
	move(-movementSpeedX, movementSpeedY);

	handleEdgeColission(windowX, windowY);

	updateAtlas();
}

/************************************************
* @brief Returns ui elements to be drawn
*************************************************/
sf::Text** Monster::getUIElements() {
	return uiController->getElements();
}

/************************************************
* @param xSteps - Steps to move in x axis
* @param ySteps - Steps to move in y axis
* @brief Moves monster by xSteps and ySteps
*************************************************/
void Monster::move(int xSteps, int ySteps) {

	int xOffset = xSteps * m_pixelScale;
	int yOffset = ySteps * m_pixelScale;
	m_sprite.setPosition(m_x + xOffset, m_y + yOffset);

	m_x += xOffset;
	m_y += yOffset;

}

/************************************************
* @brief Edge colission
*************************************************/
void Monster::handleEdgeColission(int windowX, int windowY) {
	/* Prevent from going through edges */
	int leftSidePosition = m_x - (getIntRect().width * 2);
	int rightSidePosition = m_x + (getIntRect().width * 2);
	if (leftSidePosition < 0 ||
		rightSidePosition >= windowX ||
		(double)rand() / (RAND_MAX) > 0.85) {
		changeSpeedDirection(&movementSpeedX);
		flipSprite();
	}

	/* Prevent from going through edges */
	int topSidePosition = m_y - (getIntRect().height * 2);
	int bottomSidePosition = m_y + (getIntRect().height * 2);
	if (topSidePosition <= 0 ||
		bottomSidePosition >= windowY) {

		changeSpeedDirection(&movementSpeedY);
	}
}



void Monster::nextAtlasSquare() {
	if (currentAtlasSquare() == 0)
		setIntRect(25, 0, 25, 25);
	else
		setIntRect(0, 0, 25, 25);
	return;
}

/************************************************
* @brief Cycles through the two animations of the
* picture altas
*************************************************/
int Monster::currentAtlasSquare() {
	return getIntRect().top;
}

/************************************************
* @param speed - walking speed of monster
* @brief Reverses speed
*************************************************/
void Monster::changeSpeedDirection(int* speed) {
	*speed = -(*speed);
	return;
}

/************************************************
* @param path - Path to image atlas
* @brief Sets sprite and location of monster
*************************************************/
void Monster::setSprite(const char* path) {
	m_texture.loadFromFile(path);
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(m_rectagleSource);

	m_sprite.setScale(m_pixelScale, m_pixelScale);

	m_sprite.setOrigin(m_rectagleSource.width / 2, m_rectagleSource.height / 2);
	m_sprite.setPosition(m_x, m_y);
	
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

	if (evolveTimer == EGG_HATCH_TIMER) {
		setSprite("Koromon_texture_atlas_2.png");
		if (movementSpeedX < 0) {
			flipSprite();
		}
	}
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