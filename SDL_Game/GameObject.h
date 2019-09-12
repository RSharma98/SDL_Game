#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SDL.h"
#include "SpriteRenderer.h"
#include "Vector2D.h"

class GameObject {
public:
	GameObject();
	~GameObject();
	void Initialise(const char* spritePath, SDL_Renderer* renderer, Vector2D *pos);
	void Update();
	void Render(SDL_Renderer* renderer);

private:
	SpriteRenderer* spriteRenderer;
	SDL_Rect destRect;
	Vector2D* pos;
};

#endif
