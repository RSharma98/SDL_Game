#ifndef SPIKE_OBJECT_H
#define SPIKE_OBJECT_H

#include "GameObject.h"

class SpikeObject : public GameObject
{
public:
	SpikeObject(int rotation);
	~SpikeObject();
	void Initialise(SDL_Renderer* renderer, float posX, float posY, float scaleX, float scaleY);

private:
	int rotation;
};

#endif // !SPIKE_OBJECT_H