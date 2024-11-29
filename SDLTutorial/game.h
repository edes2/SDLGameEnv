#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "player.h"
#include "soundmanager.h"

class Graphics;

class Game
{
public:
	Game();	 // Constructor
	~Game(); // Destructor
private:
	void gameLoop();
	void draw(Graphics &graphics);	// Rendering to the window
	void update(float elapsedTime); // Updating the objects

	bool initializeAudio();
	bool loadSounds();

	Player _player;

	SoundManager *soundManager;
};

#endif // GAME_H