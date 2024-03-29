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
	resetLevel = completedLevel = false;
	//Load(lvl);
}

Tilemap::~Tilemap() {
	
}

//This function loads an array and instantiates the correct game object based on a number provided
void Tilemap::Load(int arr[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			level[i][j] = arr[i][j];
			float posX = j * 64;
			float posY = i * 64;
			scale = 64;

			if (arr[i][j] == 0) {
				if (i > 0 && arr[i][j] == 0 && arr[i - 1][j] != 0) {
					CreateTile(posX, posY, scale, TileObject::TileType::Bottom);
					bounds.bottom = (i - 1) * scale;
				}
				else if (i < 9 && arr[i][j] == 0 && arr[i + 1][j] != 0) {
					CreateTile(posX, posY, scale, TileObject::TileType::Top);
					bounds.top = (i + 1) * scale;
				}
				else {
					if (j < 5) {
						if (arr[i][j + 1] == 0 && arr[i + 1][j + 1] && i < 5) {
							CreateTile(posX, posY, scale, TileObject::TileType::TopLeft);
						}
						else if (arr[i][j + 1] == 0 && arr[i - 1][j + 1] && i > 5) {
							CreateTile(posX, posY, scale, TileObject::TileType::BottomLeft);
						}
						else if (arr[i][j + 1] != 0) {
							CreateTile(posX, posY, scale, TileObject::TileType::Left);
							bounds.left = (j + 1) * scale;
						}
					}
					else {
						if (arr[i][j - 1] == 0 && arr[i + 1][j - 1] && i < 5) {
							CreateTile(posX, posY, scale, TileObject::TileType::TopRight);
						}
						else if (arr[i][j - 1] == 0 && arr[i - 1][j - 1] && i > 5) {
							CreateTile(posX, posY, scale, TileObject::TileType::BottomRight);
						}
						else if (arr[i][j - 1] != 0) {
							CreateTile(posX, posY, scale, TileObject::TileType::Right);
							bounds.right = (j - 1) * scale;
						}
					}
				}
			}
			else {
				CreateTile(posX, posY, scale, TileObject::TileType::Normal);
			}

			switch (arr[i][j]) {
			case 2: {
				LavaObject* lava = new LavaObject();
				lava->Initialise(renderer, posX, posY, scale, scale);
				lavas.push_back(lava); }
				break;
			case 3: {
				SpikeObject* spike = new SpikeObject();
				spike->Initialise(renderer, posX, posY, scale, scale);
				spikes.push_back(spike); }
				break;
			case 4: {
				CoinObject* coin = new CoinObject();
				coin->Initialise(renderer, posX, posY, scale, scale);
				coins.push_back(coin); }
				break;
			case 5: {
				player = new PlayerObject();
				player->Initialise(renderer, posX, posY, scale, scale);
				playerPosX = posX;
				playerPosY = posY; }
				break;
			case 6:
				goldenEgg = new GoldenEggObject();
				goldenEgg ->Initialise(renderer, posX, posY, scale, scale);
				break;
			default:
				break;
			}
		}
	}
	timeElapsed = 0;
}

//Function to create a specific tile
void Tilemap::CreateTile(int posX, int posY, int scale, TileObject::TileType tileType) {
	TileObject* tile = new TileObject();
	tile->Initialise(renderer, posX, posY, scale, scale, tileType);
	tiles.push_back(tile);
}

void Tilemap::Update() {
	//After 3 seconds hide the obstacles
	if (timeElapsed >= 3.0) {
		HideObstacles();
		playerCanMove = true;
	} else {
		timeElapsed += Time::GetDeltaTime();
	}

	//If the player reaches the golden egg mark this level as complete
	if (player->GetPosX() == goldenEgg->GetPosX() && player->GetPosY() == goldenEgg->GetPosY()) {
		completedLevel = true;
		playerCanMove = false;
		goldenEgg ->Hide();
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

	if(goldenEgg != NULL) goldenEgg->Render(renderer);
	if(player != NULL) player->Render(renderer);
}

void Tilemap::HideObstacles() {
	for (int i = 0; i < spikes.size(); i++) {
		spikes[i]->Hide();
	}

	for (int i = 0; i < lavas.size(); i++) {
		lavas[i]->Hide();
	}
}

//This function resets all variables for when the player dies
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

	goldenEgg->MakeVisible();

	resetLevel = false;
	completedLevel = false;
}