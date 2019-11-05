#include "Tilemap.h"

int lvl[10][10] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 8, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };
Tilemap::Tilemap(SDL_Renderer *renderer) {
	this->renderer = renderer;
	Load(lvl);
}

Tilemap::~Tilemap() {
	
}

void Tilemap::Load(int arr[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			level[i][j] = arr[i][j];
			float posX = j * 64;
			float posY = i * 64;
			float scale = 64;

			if (arr[i][j] != 0) {
				TileObject* tile = new TileObject();
				TileObject::TileType tileType;
				//TODO: Add code to TileObject to determine type of tile (i.e top/bottom/left/right wall or regular tile
				if ((i > 0 && arr[i - 1][j] == 0)) {
					if (arr[i][j + 1] == 0) tileType = TileObject::TileType::TopRight;
					else if (arr[i][j - 1] == 0) tileType = TileObject::TileType::TopLeft;
					else tileType = TileObject::TileType::Top;
				}
				else if ((i < 9 && arr[i + 1][j] == 0)) {
					if (arr[i][j + 1] == 0) tileType = TileObject::TileType::BottomRight;
					else if (arr[i][j - 1] == 0) tileType = TileObject::TileType::BottomLeft;
					else tileType = TileObject::TileType::Bottom;
				}
				else if (j > 0 && arr[i][j - 1] == 0) tileType = TileObject::TileType::Left;
				else if (j < 9 && arr[i][j + 1] == 0) tileType = TileObject::TileType::Right;
				else tileType = TileObject::TileType::Normal;
				tile->Initialise(renderer, posX, posY, scale, scale, tileType);
				tiles.push_back(tile);
			}

			switch (arr[i][j]) {
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
				break;
			default:
				break;
			}
		}
	}
}

void Tilemap::Update() {
	//TODO: Update enemies here
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