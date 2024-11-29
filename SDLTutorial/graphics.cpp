#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "graphics.h"
#include "globals.h"

Graphics::Graphics()
{
	if (SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer) < 0)
		std::cout << "Failed at SDL_CreateWindowAndRenderer()" << std::endl;
	SDL_SetWindowTitle(this->_window, "MyGame");
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(this->_window);
	SDL_DestroyRenderer(this->_renderer);
}

SDL_Surface *Graphics::loadImage(const std::string &filePath)
{
	if (this->_spriteSheets.count(filePath) == 0)
	{
		this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
	}
	return this->_spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture *texture, SDL_Rect *sourceRectangle, SDL_Rect *destinationRectangle)
{
	SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip()
{
	SDL_RenderPresent(this->_renderer); // Render Everything to the screen
}

void Graphics::clear()
{
	SDL_RenderClear(this->_renderer);
}

void Graphics::setColor(int r, int g, int b)
{
	SDL_SetRenderDrawColor(this->_renderer, r, g, b, 255);
}

void Graphics::fillRect(SDL_Rect _rect)
{
	SDL_RenderFillRect(this->_renderer, &_rect);
}

SDL_Renderer *Graphics::getRenderer() const
{
	return this->_renderer;
}
