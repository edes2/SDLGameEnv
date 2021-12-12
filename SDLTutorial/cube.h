#pragma once

#include "sprite.h"

class Graphics;

class Cube : public Sprite {
public:
	Cube();
	Cube(Graphics& graphics, float w, float h, float x, float y);
	void draw(Graphics& graphics);
	void update(float elapsedTime);


	void moveLeft();

	void moveRight();

	void moveUp();

	void moveDown();

	void stopMoving_x();
	void stopMoving_y();

private:
	float _dx, _dy;
	int _width, _height;

};