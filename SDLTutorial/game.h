#pragma once

#include "player.h"

class Graphics;

class Game
{
public:
	Game(); // Constructor
	~Game(); // Destructor
private:
	void gameLoop();
	void draw(Graphics& graphics); // Rendering to the window
	void update(float elapsedTime); // Updating the objects

	Player _player;
};

