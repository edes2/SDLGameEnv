#include <SDL.h>
#include <iostream>

#include "game.h"
#include "graphics.h"
#include "input.h"

namespace {
	const int FPS = 60;
	const int MAX_FRAME_TIME = 1000 / FPS;
}

Game::Game() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) std::cout << "Failed at SDL_Init()" << std::endl;
	this->gameLoop();
}

Game::~Game() {
	SDL_Quit();
}

void Game::gameLoop() {
	Graphics graphics;
	Input input;
	SDL_Event event;

	this->_player = Player(graphics, 100, 100, 16, 16);

	int LAST_UPDATE_TIME = SDL_GetTicks();

	while (true) {
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.repeat == 0) {
					input.keyPressed(event);
				}
			}
			else if (event.type == SDL_KEYUP) {
				input.keyReleased(event);
			}
			else if (event.type == SDL_QUIT) {
				return;
			}

		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
			return;
		}
		if (input.isKeyHeld(SDL_SCANCODE_LEFT) == true) {
			this->_player.moveLeft();
		}
		else if (input.isKeyHeld(SDL_SCANCODE_RIGHT) == true) {
			this->_player.moveRight();
		}
		if (input.isKeyHeld(SDL_SCANCODE_UP) == true) {
			this->_player.moveUp();
		}
		else if (input.isKeyHeld(SDL_SCANCODE_DOWN) == true) {
			this->_player.moveDown();
		}

		if (!input.isKeyHeld(SDL_SCANCODE_LEFT) && !input.isKeyHeld(SDL_SCANCODE_RIGHT)) {
			this->_player.stopMoving_x();
		}
		if (!input.isKeyHeld(SDL_SCANCODE_UP) && !input.isKeyHeld(SDL_SCANCODE_DOWN)) {
			this->_player.stopMoving_y();
		}

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		this->draw(graphics);
	}
}

void Game::draw(Graphics & graphics) {
	graphics.clear();

	this->_player.draw(graphics);

	graphics.flip();
}

void Game::update(float elapsedTime) {
	this->_player.update(elapsedTime);
}
