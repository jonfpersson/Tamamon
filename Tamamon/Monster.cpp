#include "Monster.h"
#include <iostream>
using namespace std;
#include <filesystem>

using std::filesystem::directory_iterator;


#define EGG_HATCH_TIMER 12

/************************************************
* @brief Constructor
*************************************************/
Monster::Monster(int x, int y, sf::IntRect rs, sf::RenderWindow* const w) {
	window = w;
	m_x = x;
	m_y = y;
	m_rectagleSource = rs;
	setSprite("egg_texture_atlas.png");

	int count = std::distance(directory_iterator("agumon_textures"), directory_iterator());
	
	int index = 0;
	for (const auto& file : directory_iterator("agumon_textures")) {
		m_textures.push_back(file.path().string());
	}

	m_uiController = new UIcontroller(window);
}

/************************************************
* @brief Destructor
*************************************************/
Monster::~Monster() {
	delete m_uiController;
}

/************************************************
* @brief Main loop
*************************************************/
void Monster::run(sf::Clock* const clock, int windowX, int windowY) {

	if (clock->getElapsedTime().asSeconds() > 0.85f) {

		if (m_timer % 10 == 0) {
			updateVitals();
		}

		animate(clock, windowX, windowY);
		clock->restart();
	}
}

/************************************************
* @brief Reduces vitals randomly
*************************************************/
void Monster::updateVitals() {
	double offset = (double) 1 / (RAND_MAX);
	m_food -= (int) (5 * offset * rand());
	m_water -= (int) (5 * offset * rand());
	m_hp -= (int) (5 * offset * rand());

	m_uiController->notifyOfChange(m_food, m_water, m_hp);

}

/************************************************
* @brief Reduces vitals randomly
*************************************************/
void Monster::giveVitalPoint(int f, int w, int h) {
	m_food += f;
	m_water += w;
	m_hp += h;

	m_uiController->notifyOfChange(m_food, m_water, m_hp);
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
	m_timer++;

	nextAtlasSquare();
	move(-m_movementSpeedX, m_movementSpeedY);

	handleEdgeColission(windowX, windowY);
}

/************************************************
* @brief Draws sprite
*************************************************/
void Monster::draw() {
	window->draw(m_sprite);
	m_uiController->draw();
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
	int leftSidePosition = m_x - (m_rectagleSource.width * 2);
	int rightSidePosition = m_x + (m_rectagleSource.width * 2);
	if (leftSidePosition < 0 ||
		rightSidePosition >= windowX ||
		(double)rand() / (RAND_MAX) > 0.85) {
		changeSpeedDirection(&m_movementSpeedX);
		flipSprite();
	}

	/* Prevent from going through edges */
	int topSidePosition = m_y - (m_rectagleSource.height * 2);
	int bottomSidePosition = m_y + (m_rectagleSource.height * 2);
	if (topSidePosition <= 0 ||
		bottomSidePosition >= windowY) {

		changeSpeedDirection(&m_movementSpeedY);
	}
}


/************************************************
* @brief Cycles between 2 atlas frames
*************************************************/
void Monster::nextAtlasSquare() {
	if (currentAtlasSquare() == 0)
		setIntRect(25, 0, 25, 25);
	else
		setIntRect(0, 0, 25, 25);

	updateAtlas();
	return;
}

/************************************************
* @brief Cycles through the two animations of the
* picture altas
*************************************************/
int Monster::currentAtlasSquare() {
	return m_rectagleSource.top;
}

/************************************************
* @param speed - walking speed of monster
* @brief Reverses speed
*************************************************/
void Monster::changeSpeedDirection(int* const speed) {
	*speed = -(*speed);
	return;
}

/************************************************
* @param path - Path to image atlas
* @brief Sets sprite and location of monster
*************************************************/
void Monster::setSprite(const char* const path) {
	UIcontroller::setSprite(path, &m_texture, &m_rectagleSource, &m_sprite, m_x, m_y, m_pixelScale);
}

/************************************************
* @brief Updates shown part of image atlas
*************************************************/
void Monster::updateAtlas() {
	m_sprite.setTextureRect(m_rectagleSource);

	if (m_timer % EGG_HATCH_TIMER == 0) {

		if (!m_textures.empty()) {
			std::string val = m_textures.front();
			setSprite(val.c_str());
			m_textures.erase(m_textures.begin());
			if (m_movementSpeedX < 0) {
				flipSprite();
			}
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