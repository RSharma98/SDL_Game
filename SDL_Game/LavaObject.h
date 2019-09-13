#ifndef LAVA_OBJECT_H
#define LAVA_OBJECT_H

#include "GameObject.h"

class LavaObject : public GameObject
{
public:
	LavaObject();
	~LavaObject();
	void Initialise(SDL_Renderer* renderer, Vector2D* pos, Vector2D* scale);
};

#endif // !LAVA_OBJECT_H