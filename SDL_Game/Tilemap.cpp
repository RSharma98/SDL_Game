#include "Tilemap.h"

int lvl[10][10] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 8, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 2, 2, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

Tilemap::Tilemap(SDL_Renderer *renderer) {
	scale = 0;
	this->renderer = renderer;
	playerCanMove = false;
	//Load(lvl);
}

Tilemap::~Tilemap() {
	
}

void Tilemap::Load(int arr[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			level[i][j] = arr[i][j];
			float posX = j * 64;
			float posY = i * 64;
			scale = 64;

			if (arr[i][j] != 0) {
				TileObject* tile = new TileObject();
				TileObject::TileType tileType;
				//TODO: Add code to TileObject to determine type of tile (i.e top/bottom/left/right wall or regular tile
				if ((i > 0 && arr[i - 1][j] == 0)) {
					if (arr[i][j + 1] == 0) tileType = TileObject::TileType::TopRight;
					else if (arr[i][j - 1] == 0) tileType = TileObject::TileType::TopLeft;
					else {
						tileType = TileObject::TileType::Top;
						bounds.top = (i + 1) * scale;
					} 
				}
				else if ((i < 9 && arr[i + 1][j] == 0)) {
					if (arr[i][j + 1] == 0) tileType = TileObject::TileType::BottomRight;
					else if (arr[i][j - 1] == 0) tileType = TileObject::TileType::BottomLeft;
					else {
						tileType = TileObject::TileType::Bottom;
						bounds.bottom = (i - 1) * scale;
					} 
				}
				else if (j > 0 && arr[i][j - 1] == 0) {
					tileType = TileObject::TileType::Left;
					bounds.left = (j + 1) * scale;
				}
				else if (j < 9 && arr[i][j + 1] == 0) {
					tileType = TileObject::TileType::Right;
					bounds.right = (j - 1) * scale;
				} 
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
			case 8: {
				player = new PlayerObject();
				player->Initialise(renderer, posX, posY, scale, scale);
				playerPosX = posX;
				playerPosY = posY; }
				break;
			default:
				break;
			}
		}
	}
	timeElapsed = 0;
}

void Tilemap::Update() {
	if (timeElapsed >= 3.0) {
		HideObstacles();
		playerCanMove = true;
	} else {
		timeElapsed += Time::GetDeltaTime();
	}

	//If the player steps on an obstacle, enable the sprite (this will be changed to cause damage later)
	for (int i = 0; i < spikes.size(); i++) {
		if (player->GetPosX() == spikes[i]->GetPosX() && player->GetPosY() == spikes[i]->GetPosY()) {
			spikes[i]->MakeVisible();
			resetLevel = true;
			playerCanMove = false;
		}
	}

	for (int i = 0; i < lavas.size(); i++) {
		if (player->GetPosX() == lavas[i]->GetPosX() && player->GetPosY() == lavas[i]->GetPosY()) {
			lavas[i]->MakeVisible();
			resetLevel = true;
			playerCanMove = false;
		}
	}
}

//These two functions only move the player if there is not a wall ahead in the direction they are moving
void Tilemap::MovePlayerHorizontal(int dir) {
	if (playerCanMove) {
		if ((player->GetPosX() <= bounds.right - scale && dir == 1) || (player->GetPosX() >= bounds.left + scale && dir == -1)) {
			player->MoveHorizontal(dir);
		}
	}
}

void Tilemap::MovePlayerVertical(int dir) {
	if (playerCanMove) {
		if ((player->GetPosY() >= bounds.top + scale && dir == 1) || (player->GetPosY() <= bounds.bottom - scale && dir == -1)) {
			player->MoveVertical(dir);
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

	player->Render(renderer);
}

void Tilemap::HideObstacles() {
	for (int i = 0; i < spikes.size(); i++) {
		spikes[i]->Hide();
	}

	for (int i = 0; i < lavas.size(); i++) {
		lavas[i]->Hide();
	}
}

void Tilemap::Reset() {
	playerCanMove = false;
	timeElapsed = 0;

	for (int i = 0; i < spikes.size(); i++) {
		spikes[i]->MakeVisible();
	}

	for (int i = 0; i < lavas.size(); i++) {
		lavas[i]->MakeVisible();
	}

	player->SetPosX(playerPosX);
	player->SetPosY(playerPosY);
	player->Update();

	resetLevel = false;
}