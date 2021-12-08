#include <SDL.h>
#include <iostream>

#include "game.h"
#include "graphics.h"
#include "input.h"

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
			std::cout << "Left Key" << std::endl;
		}
		if (input.isKeyHeld(SDL_SCANCODE_RIGHT) == true) {
			std::cout << "Right Key" << std::endl;
		}
		this->update();
	}
}

void Game::draw(Graphics & graphics) {}

void Game::update() {}
