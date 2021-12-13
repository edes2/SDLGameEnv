#include "sprite.h"
#include "graphics.h"
//#include "globals.h"

Sprite::Sprite() {}

Sprite::Sprite(Graphics& graphics, int width, int height,
	float posX, float posY) :
	_x(posX),
	_y(posY)
{
	this->_sourceRect.w = width;
	this->_sourceRect.h = height;

}

Sprite::~Sprite() {}

void Sprite::draw(Graphics& graphics, int x, int y) {
	SDL_Rect destinationRectangle = { x, y, this->_sourceRect.w,
			this->_sourceRect.h };
	graphics.fillRect(destinationRectangle);
}

void Sprite::update() {}