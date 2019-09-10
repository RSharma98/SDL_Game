#include "Game.h"

Game* game = nullptr;

int main(int args, char* argv[]) {
	const int targetFPS = 60;
	const int frameDelay = 1000 / targetFPS;
	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->Initialise("Game Name", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	while (game->Running()) {
		frameStart = SDL_GetTicks();
		game->HandleEvents();
		game->Update();
		game->Render();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game->Clean();

	return 0;
}