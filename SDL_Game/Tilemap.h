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

class Tilemap
{
public:
	Tilemap(SDL_Renderer* renderer);
	~Tilemap();
	void Render();
	void Load(int arr[16][16]);

private:
	std::vector<BackgroundObject*> backgrounds;
	std::vector<TileObject*> tiles;
	std::vector<CoinObject*> coins;
	std::vector<LavaObject*> lavas;
	std::vector<SpikeObject*> spikes;
	int level[16][16];

	SDL_Renderer* renderer;

	//TODO: make this class generate the player and enemies
	bool addedPlayer = false;
};

#endif // !Tilemap_H

