#pragma once
#include <SFML/Graphics.hpp>
#include "vitalDisplay.h"
class UIcontroller
{
private:
    sf::Font  m_font;
	sf::RenderWindow* window;
	int m_size = 3;

	vitalDisplay* vitals;

	void initTextField(sf::Text*, int, int);
	const char* icons[3] = {"icons\\pizza.png", "icons\\heart.png", "icons\\water.png"};

public:
	~UIcontroller();
	UIcontroller(sf::RenderWindow*);

	static void setSprite(const char*, sf::Texture*, sf::IntRect*, sf::Sprite*, int, int, int);

	void notifyOfChange(int, int, int);
	void draw();
};

