#include "Tilemap.h"

int lvl[16][16] = {
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };

Tilemap::Tilemap(SDL_Renderer *renderer) {
	this->renderer = renderer;
	Load(lvl);
}

Tilemap::~Tilemap() {
	
}

void Tilemap::Load(int arr[16][16]) {
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			level[i][j] = arr[i][j];
			Vector2D pos = Vector2D(j * 40, i * 40);
			Vector2D scale = Vector2D(40, 40);
			BackgroundObject* background = new BackgroundObject();
			background->Initialise(renderer, &pos, &scale);
			backgrounds.push_back(background);

			switch (arr[i][j])
			{
			case 1: {
				TileObject* tile = new TileObject();
				tile->Initialise(renderer, &pos, &scale);
				tiles.push_back(tile); }
				break;
			case 2: {
				LavaObject* lava = new LavaObject();
				lava->Initialise(renderer, &pos, &scale);
				lavas.push_back(lava); }
				break;
			case 3: {
				SpikeObject* spike = new SpikeObject(0);
				spike->Initialise(renderer, &pos, &scale);
				spikes.push_back(spike); }
				break;
			case 4: {
				SpikeObject* spike = new SpikeObject(1);
				spike->Initialise(renderer, &pos, &scale);
				spikes.push_back(spike); }
				break;
			case 5: {
				SpikeObject* spike = new SpikeObject(2);
				spike->Initialise(renderer, &pos, &scale);
				spikes.push_back(spike); }
				break;
			case 6: {
				SpikeObject* spike = new SpikeObject(3);
				spike->Initialise(renderer, &pos, &scale);
				spikes.push_back(spike); }
				break;
			case 7: {
				CoinObject* coin = new CoinObject();
				coin->Initialise(renderer, &pos, &scale);
				coins.push_back(coin); }
				break;
			default:
				break;
			}
		}
	}
}

void Tilemap::Render() {
	for (int i = 0; i < backgrounds.size(); i++) {
		backgrounds[i]->Render(renderer);
	}

	for (int i = 0; i < tiles.size(); i++) {
		tiles[i]->Render(renderer);
	}

	for (int i = 0; i < coins.size(); i++) {
		coins[i]->Render(renderer);
	}

	for (int i = 0; i < spikes.size(); i++) {
		spikes[i]->Render(renderer);
	}

	for (int i = 0; i < lavas.size(); i++) {
		lavas[i]->Render(renderer);
	}
}