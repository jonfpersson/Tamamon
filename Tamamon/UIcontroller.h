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

	void initTextField(sf::Text* const, int, int);
	const char* icons[3] = {"icons\\pizza.png", "icons\\heart.png", "icons\\water.png"};

public:
	~UIcontroller();
	UIcontroller(sf::RenderWindow* const);

	static void setSprite(const char* const, sf::Texture* const, const sf::IntRect* const, sf::Sprite* const, int, int, int);

	void notifyOfChange(int, int, int);
	void draw();
};

