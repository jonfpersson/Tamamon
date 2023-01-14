#pragma once
#include <SFML/Graphics.hpp>
class UIcontroller
{
private:
    sf::Font  m_font;
	sf::Text* m_foodTextField;
	sf::Text* m_healthTextField;
	sf::Text* m_waterTextField;

	sf::Text* initTextField(int, int);

public:
	~UIcontroller();
	UIcontroller();

	sf::Text** getElements();
};

