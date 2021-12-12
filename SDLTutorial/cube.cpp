#include "cube.h"
#include "graphics.h"

namespace cube_constants {
	const float WALK_SPEED = 0.2f;
}

Cube::Cube() {}

Cube::Cube(Graphics& graphics, float x, float y) :
	Sprite(graphics, 0, 0, 16, 16, x, y)
{

}

void Cube::moveLeft() {
	this->_dx = -cube_constants::WALK_SPEED;
}

void Cube::moveRight() {
	this->_dx = +cube_constants::WALK_SPEED;
}

void Cube::stopMoving() {
	this->_dx = 0.0f;
}

void Cube::update(float elapsedTime) {
	this->_x += this->_dx * elapsedTime;
}

void Cube::draw(Graphics& graphics) {
	Sprite::draw(graphics, this->_x, this->_y);
}