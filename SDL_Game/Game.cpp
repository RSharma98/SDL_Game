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

	//tilemap = new Tilemap(renderer);
	//level = new Level(renderer);
	levelManager = new LevelManager(renderer);
}

void Game::Update() {
	frames++;
	std::cout << frames << '\n';
	//tilemap->Update();
	//level->Update();
	levelManager->Update();
}

//This function handles keyboard movement (moving the player and quitting)
void Game::HandleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	
	switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_d:
			case SDLK_RIGHT:
				levelManager->GetCurrentTilemap()->MovePlayerHorizontal(1);
				break;
			case SDLK_a:
			case SDLK_LEFT:
				levelManager->GetCurrentTilemap()->MovePlayerHorizontal(-1);
				break;
			case SDLK_w:
			case SDLK_UP:
				levelManager->GetCurrentTilemap()->MovePlayerVertical(1);
				break;
			case SDLK_s:
			case SDLK_DOWN:
				levelManager->GetCurrentTilemap()->MovePlayerVertical(-1);
				break;
			case SDLK_r:
				levelManager->ResetLevel();
				break;
			case SDLK_RETURN:
				levelManager->IncrementLevel();
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
	SDL_SetRenderDrawColor(renderer, 36, 19, 25, 255);	//Set the background colour
	SDL_RenderClear(renderer);							//Clear the render view

	//Add stuff to render here
	//tilemap->Render();
	//level->Render();
	levelManager->Render();

	SDL_RenderPresent(renderer);						//Render the frame
}

//This function is called when the game exits
void Game::Clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned.\n";
}