#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SDL.h"
#include "SpriteRenderer.h"
#include <time.h>
#include <cstdlib>

class GameObject {
public:
	GameObject();
	~GameObject();
	void Initialise(SDL_Renderer* renderer, float posX, float posY, float scaleX, float scaleY);
	void Update();
	void Render(SDL_Renderer* renderer);
	void Hide();
	void MakeVisible();
	float GetPosX() { return posX; }
	float GetPosY() { return posY; }

protected:
	int Random(int max);
	const char* spritePath;
	SpriteRenderer* spriteRenderer;
	SDL_Rect sourceRect, destRect;
	float posX, posY;
	float scaleX, scaleY;
};

#endif
