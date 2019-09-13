#include "Game.h"
int frames;

Game::Game() {
	frames = 0;
}

Game::~Game() {

}

void Game::Initialise(const char* title, int xPos, int yPos, int width, int height, bool fullscreen) {
	int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;
	isRunning = false;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (window) std::cout << "Window created.\n";

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) std::cout << "Renderer created.\n";
		isRunning = true;
	}

	tilemap = new Tilemap(renderer);
}

void Game::Start() {

}

void Game::Update() {
	frames++;
	std::cout << frames << '\n';
}

void Game::HandleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::Render() {
	SDL_SetRenderDrawColor(renderer, 50, 0, 0, 255);
	SDL_RenderClear(renderer);

	//Add stuff to render here
	tilemap->Render();

	SDL_RenderPresent(renderer);
}

void Game::Clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned.\n";
}