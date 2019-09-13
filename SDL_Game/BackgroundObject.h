#ifndef BACKGROUND_OBJECT_H
#define BACKGROUND_OBJECT_H

#include "GameObject.h"

class BackgroundObject : public GameObject
{
public:
	BackgroundObject();
	~BackgroundObject();
	void Initialise(SDL_Renderer* renderer, Vector2D* pos);
};

#endif // !BACKGROUND_OBJECT_H