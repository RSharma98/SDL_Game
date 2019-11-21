#pragma once
#ifndef Tilemap_H
#define Tilemap_H

#include "SDL.h"
#include <vector>
#include <algorithm>
#include "SpriteRenderer.h"
#include "GameObject.h"
#include "LavaObject.h"
#include "TileObject.h"
#include "CoinObject.h"
#include "SpikeObject.h"
#include "BackgroundObject.h"
#include "PlayerObject.h"
#include "Time.h"

class Tilemap
{
public:
	Tilemap(SDL_Renderer* renderer);
	~Tilemap();
	void Render();
	void Load(int arr[10][10]);
	void Update();
	void HideObstacles();
	void MovePlayerVertical(int dir);
	void MovePlayerHorizontal(int dir);
	PlayerObject* GetPlayer() {
		return player;
	}

private:
	std::vector<BackgroundObject*> backgrounds;
	std::vector<TileObject*> tiles;
	std::vector<CoinObject*> coins;
	std::vector<LavaObject*> lavas;
	std::vector<SpikeObject*> spikes;
	PlayerObject* player;
	int level[16][16];
	float scale;
	float timeElapsed;

	SDL_Renderer* renderer;

	struct Bounds { float left, right, top, bottom; };
	Bounds bounds;

	//TODO: make this class generate the player and enemies
	bool addedPlayer = false;
};

#endif // !Tilemap_H

