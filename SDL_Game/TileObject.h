#ifndef TILE_OBJECT_H
#define TILE_OBJECT_H

#include "GameObject.h"

class TileObject : public GameObject
{
public:
	TileObject();
	~TileObject();
	enum TileType { Normal, TopLeft, TopRight, BottomLeft, BottomRight, Top, Bottom, Left, Right };
	void Initialise(SDL_Renderer* renderer, float posX, float posY, float scaleX, float scaleY, TileType tileType);
};

#endif // !TILE_OBJECT_H