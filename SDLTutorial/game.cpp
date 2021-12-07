#include <SDL.h>

#include "game.h"
#include "graphics.h"

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game() {
	SDL_Quit();
}

void Game::gameLoop() {
	Graphics graphics;
	SDL_Event e;

	while (true) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				return;
			}

			this->update();
		}
	}
}

void Game::draw(Graphics & graphics) {}

void Game::update() {}
