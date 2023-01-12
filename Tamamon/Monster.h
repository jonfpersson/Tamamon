#pragma once
#include <SFML/Graphics.hpp>
using std::string;

class Monster
{
private:
	int   m_x;
	int   m_y;
	float m_pixelScale = 5.0f;
	int movementSpeedX = 5;
	int movementSpeedY = 3;

	int m_food = 100;
	int m_hp = 100;
	int m_water = 100;
	
	sf::Texture m_texture;
	sf::IntRect m_rectagleSource;
	sf::Sprite  m_sprite;

public: 
	Monster(int x, int y, sf::IntRect rs) {
		m_x = x;
		m_y = y;
		m_rectagleSource = rs;
	}
	
	sf::Sprite  getSprite();
	sf::IntRect getIntRect();
	int topSidePosition();
	int bottomSidePosition();
	void nextAtlasSquare();
	int currentAtlasSquare();
	int leftSidePosition();
	int rightSidePosition();
	void changeSpeedDirection(int*);
	void setIntRect(int, int, int, int);
	void move(int, int);
	void setSprite(const char*);
	void updateAtlas();
	void flipSprite();
	void animate(sf::Clock* const, int, int);

	int getFoodLevel();
	int getHpLevel();
	int getWaterLevel();

	int getX();
	int getY();
};

