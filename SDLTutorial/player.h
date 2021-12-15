#pragma once

#include "animatedsprite.h"
#include "globals.h"

class Graphics;

class Player : public AnimatedSprite {
public:
	Player();
	Player(Graphics& graphics, float x, float y, float w, float h);
	void draw(Graphics& graphics);
	void update(float elapsedTime);

	void moveLeft();

	void moveRight();

	void moveUp();

	void moveDown();

	void stopMoving_x();
	void stopMoving_y();

	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();

private:
	float _dx, _dy;

	float _width, _height;

	Direction _facing;

};