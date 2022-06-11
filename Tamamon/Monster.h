#pragma once
#include <SFML/Graphics.hpp>
using std::string;

class Monster
{
private:
	int m_x;
	int m_y;
	float m_pixelScale = 5.0f;

	sf::Texture m_texture;
	sf::IntRect m_rectagleSource;
	sf::Sprite m_sprite;

public: 

	Monster(int x, int y, sf::IntRect rs) {
		m_x = x;
		m_y = y;
		m_rectagleSource = rs;
	}
	
	sf::Sprite getSprite();
	sf::IntRect getIntRect();
	void setIntRect(int, int, int, int);
	void move(int, int);
	void setSprite(string);

	void updateRect();
};

