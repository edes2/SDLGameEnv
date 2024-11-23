#include <SDL.h>
#include <iostream>

#include "game.h"
#include "graphics.h"
#include "input.h"
#include "globals.h"

namespace {
	const int FPS = 60;
	const int MAX_FRAME_TIME = 1000 / FPS;
}

Game::Game() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        return;
    }

	if (!initializeAudio()) {
        printf("Failed to initialize audio!\n");
        return;
    }

	gJump = Mix_LoadWAV( "content/sounds/jump.wav" );
    if( gJump == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        return;
    }

    this->gameLoop();
}

Game::~Game() {
	Mix_FreeChunk( gJump );
	gJump = NULL;
	Mix_Quit();
    SDL_Quit();
}

void Game::gameLoop() {
	Graphics graphics;
	Input input;
	SDL_Event event;

	this->_player = Player(graphics, 100.0f, globals::SCREEN_HEIGHT - 16.0f, 16.0f, 16.0f);

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
		if (input.isKeyHeld(SDL_SCANCODE_SPACE) == true) {
			if (gJump == nullptr) {
				printf("Jump sound not loaded\n");
				return;
			}

			// Check if jump sound is already playing
			if (!Mix_Playing(1)) {
				int channel = Mix_PlayChannel(1, gJump, 0);
				if (channel == -1) {
					printf("Mix_PlayChannel failed: %s\n", Mix_GetError());
				}
			}
			this->_player.jump();

		}
		if (!input.isKeyHeld(SDL_SCANCODE_LEFT) && !input.isKeyHeld(SDL_SCANCODE_RIGHT)) {
			this->_player.stopMoving_x();
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

bool Game::initializeAudio() {
    //Initialize SDL_mixer
	if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
	{
		printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
		return false;
	}
	return true;
}

