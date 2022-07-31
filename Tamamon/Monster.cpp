#include "Monster.h"
#include <iostream>
using namespace std;

void Monster::move(int xSteps, int ySteps){

	int xOffset = xSteps * m_pixelScale;
	int yOffset = ySteps * m_pixelScale;
	m_sprite.setPosition(m_x + xOffset, m_y + yOffset);
	
	m_x += xOffset;
	m_y += yOffset;

}

void Monster::setSprite(string path) { 
	m_texture.loadFromFile(path);
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(m_rectagleSource);
	
	m_sprite.scale(m_pixelScale, m_pixelScale);
	m_x = 100;
	m_y = 0;
	m_sprite.setOrigin(m_rectagleSource.width / 2, 0);

	m_sprite.setPosition(m_x, m_y);
}

int Monster::getX() {
	return m_x;
}

int Monster::getY() {
	return m_y;
}

void Monster::updateRect() {
	m_sprite.setTextureRect(m_rectagleSource);
}

sf::Sprite Monster::getSprite() {
	return m_sprite;
}

void Monster::flipSprite() {
	m_sprite.scale(-1, 1);
}

sf::IntRect Monster::getIntRect() {
	return m_rectagleSource;
}

void Monster::setIntRect(int top, int left, int height, int width) {
	m_rectagleSource.top = top;
	m_rectagleSource.left = left;
	m_rectagleSource.height = height;
	m_rectagleSource.width = width;

}