#pragma once
#include <SFML/Graphics.hpp>
using std::string;
#include  "UIcontroller.h"

#define VITAL_START_VALUE 100

class Monster
{
private:
	std::vector<std::string> m_textures;
	int   m_x;
	int   m_y;
	int m_pixelScale = 5;
	int m_movementSpeedX = 5;
	int m_movementSpeedY = 3;
	long m_timer = 0;

	int m_food = VITAL_START_VALUE;
	int m_hp = VITAL_START_VALUE;
	int m_water = VITAL_START_VALUE;
	
	UIcontroller* m_uiController;

	sf::Texture m_texture;
	sf::IntRect m_rectagleSource;
	sf::Sprite  m_sprite;

	sf::RenderWindow* window;
	void updateVitals();
	void nextAtlasSquare();
	int currentAtlasSquare();
	void changeSpeedDirection(int* const);
	void handleEdgeColission(int, int);
	void setSprite(const char* const);
	void updateAtlas();
	void flipSprite();
	void move(int, int);
	void setIntRect(int, int, int, int);

public: 
	Monster(int x, int y, sf::IntRect rs, sf::RenderWindow* const);
	~Monster();

	void animate(sf::Clock* const, int, int);
	void run(sf::Clock* const, int, int);

	sf::Sprite  getSprite();
	void draw();
	void giveVitalPoint(int, int, int);
};

