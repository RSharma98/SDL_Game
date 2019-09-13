#ifndef SPIKE_OBJECT_H
#define SPIKE_OBJECT_H

#include "GameObject.h"

class SpikeObject : public GameObject
{
public:
	SpikeObject(int rotation);
	~SpikeObject();
	void Initialise(SDL_Renderer* renderer, Vector2D* pos, Vector2D* scale);

private:
	int rotation;
};

#endif // !SPIKE_OBJECT_H