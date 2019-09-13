#include "Tilemap.h"

int lvl[16][16] = {
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1} };

Tilemap::Tilemap() {
	backgrounds = new std::vector<SpriteRenderer>();
	sprites = new std::vector<SpriteRenderer>();
	Load(lvl);
}

Tilemap::~Tilemap() {
	
}

void Tilemap::Load(int arr[16][16]) {
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			level[i][j] = arr[i][j];
		}
	}
}

void Tilemap::Render(SDL_Renderer *renderer) {

	//Render a background on all tiles then the other tiles above it.
	//KEY:
	//1: TILE
	//2: LAVA
	//3: SPIKES
	//4: COINS
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			SpriteRenderer *sprite = new SpriteRenderer();
			switch (level[i][j])
			{
			default:
				break;
			case 1:
				//Tile
				SDL_Rect sourceRect{0, 0, 16, 16};
				SDL_Rect destRect{j * 40, i * 40, 40, 40};
				sprite->Initialise(tilePath, renderer, sourceRect, destRect);
				sprite->Render(renderer, destRect);
				break;
			/*case 2:
				//Player
				break;
			case 3:
				//Enemy
				break;
			case 4:
				//Spikes?
				break;*/
			}
		}
	}
}