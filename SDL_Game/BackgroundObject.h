#ifndef BACKGROUND_OBJECT_H
#define BACKGROUND_OBJECT_H

#include "GameObject.h"

class BackgroundObject : public GameObject
{
public:
	BackgroundObject();
	~BackgroundObject();
	void Initialise(SDL_Renderer* renderer, float posX, float posY, float scaleX, float scaleY);
};

#endif // !BACKGROUND_OBJECT_H