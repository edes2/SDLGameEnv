#pragma once

#include <SDL2/SDL.h>
#include <map>

class Input
{
public:
	void clearInput();
	void keyReleased(const SDL_Event& event);
	void keyPressed(const SDL_Event& event);

	bool wasKeyPressed(SDL_Scancode key);
	bool wasKeyReleased(SDL_Scancode key);
	bool isKeyHeld(SDL_Scancode key);
private:
	std::map<SDL_Scancode, bool> _heldKeys; // Keep track of held keys
	std::map<SDL_Scancode, bool> _pressedKeys; // Pressed keys
	std::map<SDL_Scancode, bool> _releasedKeys; // Released keys
};

