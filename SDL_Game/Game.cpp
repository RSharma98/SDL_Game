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
	tilemap->Update();
}

void Game::HandleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	
	switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_d:
			case SDLK_RIGHT:
				tilemap->GetPlayer()->MoveHorizontal(1);
				break;
			case SDLK_a:
			case SDLK_LEFT:
				tilemap->GetPlayer()->MoveHorizontal(-1);
				break;
			case SDLK_w:
			case SDLK_UP:
				tilemap->GetPlayer()->MoveVertical(1);
				break;
			case SDLK_s:
			case SDLK_DOWN:
				tilemap->GetPlayer()->MoveVertical(-1);
				break;
			case SDLK_ESCAPE:
				isRunning = false;
				break;
			default:
				break;
			}
			break;
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::Render() {
	SDL_SetRenderDrawColor(renderer, 36, 19, 25, 255);
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