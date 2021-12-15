#include "player.h"
#include "graphics.h"
#include "globals.h"

namespace player_constants {
	const float WALK_SPEED = 0.2f;
}

Player::Player() {}

Player::Player(Graphics& graphics, float x, float y, float w, float h) :
	AnimatedSprite(graphics, "content/sprites/MyChar.png", 0, 0, w, h, x, y, 100), // 16 and 16 is the pixel player width in the png
	_width(w),
	_height(h)
{
	this->setupAnimations();
	this->playAnimation("RunRight");
}

void Player::setupAnimations() {
	this->addAnimation(1, 0, 0, "IdleLeft", _width, _height, Vector2(0, 0));
	this->addAnimation(1, 0, 16, "IdleRight", _width, _height, Vector2(0, 0));
	this->addAnimation(3, 0, 0, "RunLeft", _width, _height, Vector2(0, 0));
	this->addAnimation(3, 0, 16, "RunRight", _width, _height, Vector2(0, 0));
}

void Player::animationDone(std::string currentAnimation) {}

void Player::moveLeft() {
	this->_dx = -player_constants::WALK_SPEED;
	this->playAnimation("RunLeft");
	this->_facing = LEFT;
}

void Player::moveRight() {
	this->_dx = player_constants::WALK_SPEED;
	this->playAnimation("RunRight");
	this->_facing = RIGHT;
}

void Player::moveUp() {
	this->_dy = -player_constants::WALK_SPEED;
}

void Player::moveDown() {
	this->_dy = +player_constants::WALK_SPEED;
}

void Player::stopMoving_x() {
	this->_dx = 0.0f;
	this->playAnimation(this->_facing == RIGHT ? "IdleRight" : "IdleLeft");
}

void Player::stopMoving_y() {
	this->_dy = 0.0f;
}

void Player::update(float elapsedTime) {
	this->_x += this->_dx * elapsedTime;
	this->_y += this->_dy * elapsedTime;

	AnimatedSprite::update(elapsedTime);
	if ((this->_x + this->_width * globals::SPRITE_SCALE) > globals::SCREEN_WIDTH) this->_x = globals::SCREEN_WIDTH - this->_width * globals::SPRITE_SCALE;
	if (this->_x < 0) this->_x = 0;

	if ((this->_y + this->_height * globals::SPRITE_SCALE) > globals::SCREEN_HEIGHT) this->_y = globals::SCREEN_HEIGHT - this->_height * globals::SPRITE_SCALE;
	if (this->_y < 0) this->_y = 0;
}

void Player::draw(Graphics& graphics) {
	AnimatedSprite::draw(graphics, this->_x, this->_y);
}