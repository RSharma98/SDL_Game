#ifndef TILE_OBJECT_H
#define TILE_OBJECT_H

#include "GameObject.h"

class TileObject : public GameObject
{
public:
	TileObject();
	~TileObject();
	void Initialise(SDL_Renderer* renderer, float posX, float posY, float scaleX, float scaleY);
};

#endif // !TILE_OBJECT_H