#include <SDL.h>
#include <iostream>

#include "graphics.h"

Graphics::Graphics() {
	if (SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer) < 0 ) std::cout << "Failed at SDL_CreateWindowAndRenderer()" << std::endl;
	SDL_SetWindowTitle(this->_window, "MyGame");
}

Graphics::~Graphics() {
	SDL_DestroyWindow(this->_window);
	SDL_DestroyRenderer(this->_renderer);
}

void Graphics::flip() {
	SDL_RenderPresent(this->_renderer); // Render Everything to the screen
}

void Graphics::clear() {
	this->setColor(0, 0, 0);
	SDL_RenderClear(this->_renderer);
}

void Graphics::setColor(int r, int g, int b) {
	SDL_SetRenderDrawColor(this->_renderer, r, g, b, 255);
}

void Graphics::fillRect(SDL_Rect _rect) {
	SDL_RenderFillRect(this->_renderer, &_rect);
}

SDL_Renderer* Graphics::getRenderer() const {
	return this->_renderer;
}
