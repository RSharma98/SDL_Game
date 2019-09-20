#include "Tilemap.h"

int lvl[16][16] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
	{1, 8, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 1, 1, 1},
	{1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
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
			float posX = j * 40;
			float posY = i * 40;
			float scale = 40;
			BackgroundObject* background = new BackgroundObject();
			background->Initialise(renderer, posX, posY, scale, scale);
			backgrounds.push_back(background);

			switch (arr[i][j])
			{
			case 1: {
				TileObject* tile = new TileObject();
				tile->Initialise(renderer, posX, posY, scale, scale);
				tiles.push_back(tile); }
				break;
			case 2: {
				LavaObject* lava = new LavaObject();
				lava->Initialise(renderer, posX, posY, scale, scale);
				lavas.push_back(lava); }
				break;
			case 3: {
				SpikeObject* spike = new SpikeObject(0);
				spike->Initialise(renderer, posX, posY, scale, scale);
				spikes.push_back(spike); }
				break;
			case 4: {
				SpikeObject* spike = new SpikeObject(1);
				spike->Initialise(renderer, posX, posY, scale, scale);
				spikes.push_back(spike); }
				break;
			case 5: {
				SpikeObject* spike = new SpikeObject(2);
				spike->Initialise(renderer, posX, posY, scale, scale);
				spikes.push_back(spike); }
				break;
			case 6: {
				SpikeObject* spike = new SpikeObject(3);
				spike->Initialise(renderer, posX, posY, scale, scale);
				spikes.push_back(spike); }
				break;
			case 7: {
				CoinObject* coin = new CoinObject();
				coin->Initialise(renderer, posX, posY, scale, scale);
				coins.push_back(coin); }
				break;
			case 8:
				player = new PlayerObject();
				player->Initialise(renderer, posX, posY, scale, scale);
			default:
				break;
			}
		}
	}
}

void Tilemap::Update() {
	if (player != nullptr) player->Update();
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

	player->Render(renderer);
}