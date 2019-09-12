#include "GameObject.h"

GameObject::GameObject() {
	spriteRenderer = new SpriteRenderer();
}

GameObject::~GameObject() {

}

void GameObject::Initialise(const char *spritePath, SDL_Renderer *renderer, Vector2D *pos) {
	SDL_Rect dest{ 0, 0, 0, 0 };
	SDL_Rect source{ 0, 0, 0, 0 };
	spriteRenderer->Initialise(spritePath, renderer, source, dest);
	this->pos = pos;
}

void GameObject::Update() {
	destRect.h = destRect.w = 64;
	destRect.x = pos->getX();
	destRect.y = pos->getY();
	//Todo, update sprite renderer values based on object's transform
}

void GameObject::Render(SDL_Renderer *renderer) {
	spriteRenderer->Render(renderer, destRect);
}