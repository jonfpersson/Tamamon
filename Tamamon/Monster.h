#pragma once
#include <SFML/Graphics.hpp>
using std::string;
using std::unique_ptr;
using std::make_unique;
#include  "UIcontroller.h"

class Monster
{
private:
	int   m_x;
	int   m_y;
	float m_pixelScale = 5.0f;
	int m_movementSpeedX = 5;
	int m_movementSpeedY = 3;
	long m_timer = 0;

	int m_food = 100;
	int m_hp = 100;
	int m_water = 100;
	
	UIcontroller* m_uiController;

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
	sf::IntRect getIntRect();
	int getFoodLevel();
	int getHpLevel();
	int getWaterLevel();
public: 
	Monster(int x, int y, sf::IntRect rs);
	~Monster();

	void animate(sf::Clock* const, int, int);
	void run(sf::Clock* const, int, int);
	sf::Text** getUIElements();;

	sf::Sprite  getSprite();
	
};

