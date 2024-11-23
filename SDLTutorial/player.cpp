#include "player.h"
#include "graphics.h"
#include "globals.h"

namespace player_constants {
	const float WALK_SPEED = 0.2f;
	const float GRAVITY = 0.0017f;
	const float JUMP_VELOCITY = -0.71f;
}

Player::Player() {}

Player::Player(Graphics& graphics, float x, float y, float w, float h) :
	AnimatedSprite(graphics, "content/sprites/MyChar.png", 0, 0, w, h, x, y, 100.0f), // 16 and 16 is the pixel player width in the png
	_width(w),
	_height(h),
	_jumpSound(nullptr)

{
	_jumpSound = Mix_LoadMUS("content/sounds/jump.mp3");
    if (_jumpSound == nullptr) {
        printf("Mix_LoadMUS error: %s\n", Mix_GetError());
    }

	this->isJumping = false;
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

void Player::stopMoving_x() {
	this->_dx = 0.0f;
	this->playAnimation(this->_facing == RIGHT ? "IdleRight" : "IdleLeft");
}

void Player::stopMoving_y() {
	this->_dy = 0.0f;
}

void Player::jump() {
    if (!this->isJumping) {
        this->_dy = player_constants::JUMP_VELOCITY;
        this->isJumping = true;
        
        if (_jumpSound != nullptr) {
            if (Mix_PlayingMusic() == 0) { // Only play if no music is currently playing
                if (Mix_PlayMusic(_jumpSound, 0) == -1) {
                    printf("Mix_PlayMusic error: %s\n", Mix_GetError());
                }
            }
        }
    }
}

void Player::update(float elapsedTime) {
    this->_dy += player_constants::GRAVITY * elapsedTime;
	this->_x += this->_dx * elapsedTime;
	this->_y += this->_dy * elapsedTime;

	// Ground collision
    float groundLevel = globals::SCREEN_HEIGHT - this->_height * globals::SPRITE_SCALE;
    if (this->_y >= groundLevel) {
        this->_y = groundLevel;
        this->_dy = 0.0f;
        this->isJumping = false;
    }

	// Ceiling collision
    if (this->_y < 0.0f) {
        this->_y = 0.0f;
        this->_dy = 0.0f;
    }

	// Horizontal bounds
    if ((this->_x + this->_width * globals::SPRITE_SCALE) > globals::SCREEN_WIDTH) {
        this->_x = globals::SCREEN_WIDTH - this->_width * globals::SPRITE_SCALE;
    }
    if (this->_x < 0.0f) {
        this->_x = 0.0f;
    }

	AnimatedSprite::update(elapsedTime);
}

void Player::draw(Graphics& graphics) {
	AnimatedSprite::draw(graphics, this->_x, this->_y);
}

Player::~Player() {
    if (_jumpSound != nullptr) {
        Mix_HaltMusic();
        Mix_FreeMusic(_jumpSound);
        _jumpSound = nullptr;
    }
}