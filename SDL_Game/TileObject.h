#ifndef TILE_OBJECT_H
#define TILE_OBJECT_H

#include "GameObject.h"

class TileObject : public GameObject
{
public:
	TileObject();
	~TileObject();
	void Initialise(SDL_Renderer* renderer, Vector2D* pos, Vector2D* scale);
};

#endif // !TILE_OBJECT_H