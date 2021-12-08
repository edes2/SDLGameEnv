#include "input.h"

void Input::clearInput() {	// Clear the Maps of pressed and release keys (We want to take only the new inputs in this frame)
	this->_pressedKeys.clear();
	this->_releasedKeys.clear();
}

void Input::keyPressed(const SDL_Event& event) {
	this->_pressedKeys[event.key.keysym.scancode] = true; // Add the key to the pressedKeys map
	this->_heldKeys[event.key.keysym.scancode] = true; // Add the key to the heldKeys map
}

void Input::keyReleased(const SDL_Event& event) {
	this->_releasedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = false;
}

bool Input::wasKeyPressed(SDL_Scancode key) {
	return this->_pressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key) {
	return this->_releasedKeys[key];
}

bool Input::isKeyHeld(SDL_Scancode key) {
	return this->_heldKeys[key];
}