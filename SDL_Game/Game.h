#ifndef  GAME_H
#define GAME_H

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

#include "SpriteRenderer.h"

class Game {
public:
	Game();
	~Game();

	void Initialise(const char *title, int xPos, int yPos, int width, int height, bool fullscreen);
	void Start();
	void Update();
	void HandleEvents();
	void Render();
	void Clean();
	bool Running() { return isRunning; }

private:
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;

	SpriteRenderer playerSprite;
};

#endif // ! GAME_H