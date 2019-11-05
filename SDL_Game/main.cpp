#include "Game.h"

Game* game = nullptr;

int main(int args, char* argv[]) {
	//These variables are used to limit the frame rate to 60fps
	const int targetFPS = 60;
	const int frameDelay = 1000 / targetFPS;
	Uint32 frameStart;
	int frameTime;

	game = new Game();	//Initialise the game
	game->Initialise("SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 640, false);
	while (game->Running()) {			//While the game is running
		frameStart = SDL_GetTicks();	//Get the ticks at the start of the frame
		game->HandleEvents();			//Check for events (input)
		game->Update();					//Update the game
		game->Render();					//Render the game

		//Find how long has elapsed since the last frame and wait as needed to reach 60fps
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
	//Clean the game if it's not running
	game->Clean();

	return 0;
}