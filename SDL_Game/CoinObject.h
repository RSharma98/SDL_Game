#ifndef COIN_OBJECT_H
#define COIN_OBJECT_H

#include "GameObject.h"

class CoinObject : public GameObject
{
public:
	CoinObject();
	~CoinObject();
	void Initialise(SDL_Renderer* renderer, float posX, float posY, float scaleX, float scaleY);
};

#endif // !COIN_OBJECT_H