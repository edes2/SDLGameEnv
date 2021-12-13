#pragma once

#include <SDL.h>

#include <string>

class Graphics;

class Sprite {
public:
	Sprite();
	Sprite(Graphics& graphics, int width, int height,
		float posX, float posY);
	virtual ~Sprite();
	virtual void update();
	void draw(Graphics& graphics, int x, int y);

protected:
	SDL_Rect _sourceRect;

	float _x, _y;
private:
};