#include "cube.h"
#include "graphics.h"
#include "globals.h"

namespace cube_constants {
	const float WALK_SPEED = 0.2f;
}

Cube::Cube() {}

Cube::Cube(Graphics& graphics, float w, float h, float x, float y) :
	Sprite(graphics, w, h, x, y),
	_width(w),
	_height(h)
{

}

void Cube::moveLeft() {
	this->_dx = -cube_constants::WALK_SPEED;
}

void Cube::moveRight() {
	this->_dx = +cube_constants::WALK_SPEED;
}

void Cube::moveUp() {
	this->_dy = -cube_constants::WALK_SPEED;
}

void Cube::moveDown() {
	this->_dy = +cube_constants::WALK_SPEED;
}

void Cube::stopMoving_x() {
	this->_dx = 0.0f;
}

void Cube::stopMoving_y() {
	this->_dy = 0.0f;
}

void Cube::update(float elapsedTime) {
	this->_x += this->_dx * elapsedTime;
	this->_y += this->_dy * elapsedTime;
	if ((this->_x + this->_width) > globals::SCREEN_WIDTH) this->_x = globals::SCREEN_WIDTH- this->_width;
	if (this->_x < 0) this->_x = 0;

	if ((this->_y + this->_height) > globals::SCREEN_HEIGHT) this->_y = globals::SCREEN_HEIGHT - this->_height;
	if (this->_y < 0) this->_y = 0;
}

void Cube::draw(Graphics& graphics) {
	graphics.setColor(255, 255, 255);
	Sprite::draw(graphics, this->_x, this->_y);
	graphics.setColor(0, 0, 0);
}