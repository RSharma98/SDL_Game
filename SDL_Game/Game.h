#ifndef  GAME_H
#define GAME_H

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

#include "GameObject.h"
#include "LavaObject.h"
#include "TileObject.h"
#include "Tilemap.h"

class Game {
public:
	Game();
	~Game();

	void Initialise(const char *title, int xPos, int yPos, int width, int height, bool fullscreen);
	void Update();
	void HandleEvents();
	void Render();
	void Clean();
	bool Running() { return isRunning; }

private:
	bool isRunning = false;
	SDL_Window *window;
	SDL_Renderer *renderer;

	Tilemap* tilemap;
};

#endif // ! GAME_H