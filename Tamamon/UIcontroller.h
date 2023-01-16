#pragma once
#include <SFML/Graphics.hpp>
#include "vitalDisplay.h"
class UIcontroller
{
private:
    sf::Font  m_font;

	int m_size = 3;

	vitalDisplay* vitals;

	sf::Text* initTextField(sf::Text*, int, int);
	const char* icons[3] = {"icons\\pizza.png", "icons\\heart.png", "icons\\water.png"};

public:
	~UIcontroller();
	UIcontroller();

	static void setSprite(const char*, sf::Texture*, sf::IntRect*, sf::Sprite*, int, int, int);

	vitalDisplay** getElements();
	void notifyOfChange(int, int, int);
};

