#ifndef GOLDENEGGOBJECT_H
#define GOLDENEGGOBJECT_H

#include "GameObject.h"

class GoldenEggObject : public GameObject {
public:
	GoldenEggObject();
	~GoldenEggObject();
	void Initialise(SDL_Renderer* renderer, float posX, float posY, float scaleX, float scaleY);
};
#endif // !GOLDENEGGOBJECT_H
