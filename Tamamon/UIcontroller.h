#pragma once
#include <SFML/Graphics.hpp>
class UIcontroller
{
private:
    sf::Font font;
	sf::Text* foodTextField;
	sf::Text* healthTextField;
	sf::Text* waterTextField;

	sf::Text* initTextField(int, int);

public:
	~UIcontroller();
	UIcontroller();

	sf::Text** getElements();
};

