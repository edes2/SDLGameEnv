#pragma once

#include "animatedsprite.h"
#include "globals.h"
#include <SDL_mixer.h>


class Graphics;

class Player : public AnimatedSprite {
public:
	Player();
	~Player();
	Player(Graphics& graphics, float x, float y, float w, float h);
	void draw(Graphics& graphics);
	void update(float elapsedTime);

	void moveLeft();
	void moveRight();

	void stopMoving_x();
	void stopMoving_y();

	void jump();

	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();

private:
	float _dx, _dy;

	float _width, _height;

	Direction _facing;

	bool isJumping;
    Mix_Music* _jumpSound;


};