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

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		this->draw(graphics);
	}
}

void Game::draw(Graphics & graphics) {}

void Game::update(float elapsedTime) {}
