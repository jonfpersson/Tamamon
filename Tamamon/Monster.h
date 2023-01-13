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
	int evolveTimer = 0;

	int m_food = 100;
	int m_hp = 100;
	int m_water = 100;
	
	sf::Texture m_texture;
	sf::IntRect m_rectagleSource;
	sf::Sprite  m_sprite;

	void nextAtlasSquare();
	int currentAtlasSquare();
	void changeSpeedDirection(int*);
	void handleEdgeColission(int, int);
	void setSprite(const char*);
	void updateAtlas();
	void flipSprite();
	void move(int, int);
	void setIntRect(int, int, int, int);

public: 
	Monster(int x, int y, sf::IntRect rs) {
		m_x = x;
		m_y = y;
		m_rectagleSource = rs;
		setSprite("egg_texture_atlas.png");
	}
	void animate(sf::Clock* const, int, int);

	sf::Sprite  getSprite();
	sf::IntRect getIntRect();
	
	int getFoodLevel();
	int getHpLevel();
	int getWaterLevel();

	int getX();
	int getY();
};

