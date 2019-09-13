#ifndef COIN_OBJECT_H
#define COIN_OBJECT_H

#include "GameObject.h"

class CoinObject : public GameObject
{
public:
	CoinObject();
	~CoinObject();
	void Initialise(SDL_Renderer* renderer, Vector2D* pos);
};

#endif // !COIN_OBJECT_H