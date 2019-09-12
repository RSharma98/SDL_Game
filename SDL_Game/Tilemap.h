#pragma once
#ifndef Tilemap_H
#define Tilemap_H

#include "SDL.h"
#include <vector>
#include "SpriteRenderer.h"

class Tilemap
{
public:
	Tilemap();
	~Tilemap();
	void Render(SDL_Renderer *renderer);
	void Load(int arr[10][10]);

private:
	std::vector<SpriteRenderer>* backgrounds;
	std::vector<SpriteRenderer>* sprites;
	const char* tilePath = "Assets/Sprites/microFantasy.v0.4/tilesets/platformer.png";
	int level[10][10];

	//TODO: make this class generate the player and enemies
	bool addedPlayer = false;
};

#endif // !Tilemap_H

