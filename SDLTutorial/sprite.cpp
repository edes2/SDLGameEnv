#include "sprite.h"
#include "graphics.h"
#include "globals.h"

Sprite::Sprite() {}

Sprite::Sprite(Graphics& graphics, int sourceX, int sourceY, int width, int height,
	float posX, float posY) :
	_x(posX),
	_y(posY)
{
	this->_sourceRect.x = sourceX;
	this->_sourceRect.y = sourceY;
	this->_sourceRect.w = width;
	this->_sourceRect.h = height;

}

Sprite::~Sprite() {}

void Sprite::draw(Graphics& graphics, int x, int y) {
	SDL_Rect destinationRectangle = { x, y, this->_sourceRect.w,
			this->_sourceRect.h };
	graphics.setColor(255, 255, 255);
	graphics.fillRect(destinationRectangle);
}

void Sprite::update() {}