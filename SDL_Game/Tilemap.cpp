#include "Tilemap.h"

int lvl[10][10] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, };

Tilemap::Tilemap() {
	backgrounds = new std::vector<SpriteRenderer>();
	sprites = new std::vector<SpriteRenderer>();
	Load(lvl);
}

Tilemap::~Tilemap() {
	
}

void Tilemap::Load(int arr[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			level[i][j] = arr[i][j];
		}
	}
}

void Tilemap::Render(SDL_Renderer *renderer) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			SpriteRenderer *sprite = new SpriteRenderer();
			switch (level[i][j])
			{
			default:
				break;
			case 1:
				//Tile
				SDL_Rect sourceRect{8, 0, 8, 8};
				SDL_Rect destRect{j * 64, i * 64, 64, 64};
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