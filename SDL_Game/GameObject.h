#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SDL.h"
#include "SpriteRenderer.h"
#include "Vector2D.h"
#include <time.h>
#include <cstdlib>

class GameObject {
public:
	GameObject();
	~GameObject();
	void Initialise(SDL_Renderer* renderer, Vector2D *pos, Vector2D *scale);
	void Update();
	void Render(SDL_Renderer* renderer);

protected:
	int Random(int max);
	const char* spritePath;
	SpriteRenderer* spriteRenderer;
	SDL_Rect sourceRect, destRect;
	Vector2D* pos;
	Vector2D* scale;
};

#endif
