#include "GameObject.h"

GameObject::GameObject() {
	
}

GameObject::~GameObject() {

}

void GameObject::Initialise(SDL_Renderer *renderer, Vector2D *pos, Vector2D *scale) {
	spriteRenderer = new SpriteRenderer();
	this->pos = pos;
	this->scale = scale;

	destRect.x = pos->getX();
	destRect.y = pos->getY();
	destRect.w = scale->getX();
	destRect.h = scale->getY();
	spriteRenderer->Initialise(spritePath, renderer, sourceRect, destRect);
}

void GameObject::Update() {
	destRect.x = pos->getX();
	destRect.y = pos->getY();
	destRect.w = scale->getX();
	destRect.h = scale->getY();
	//Todo, update sprite renderer values based on object's transform
}

void GameObject::Render(SDL_Renderer *renderer) {
	spriteRenderer->Render(renderer, destRect);
}


int GameObject::Random(int max){
	static bool first = true;
	if (first)
	{
		srand(time(NULL)); //seeding for the first time only!
		first = false;
	}
	return rand() % (max + 1);
}