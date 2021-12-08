#include <SDL.h>

#include "graphics.h"

Graphics::Graphics() {
	if (SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer) < 0 ) std::cout << "Failed at SDL_CreateWindowAndRenderer()" << std::endl;
	SDL_SetWindowTitle(this->_window, "MyGame");
}

Graphics::~Graphics() {
	SDL_DestroyWindow(this->_window);
	SDL_DestroyRenderer(this->_renderer);.
}
