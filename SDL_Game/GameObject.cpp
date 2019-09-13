#include "GameObject.h"

GameObject::GameObject() {
	
}

GameObject::~GameObject() {

}

void GameObject::Initialise(SDL_Renderer *renderer, Vector2D *pos) {
	spriteRenderer = new SpriteRenderer();
	spriteRenderer->Initialise(spritePath, renderer, sourceRect, destRect);
	this->pos = pos;
}

void GameObject::Update() {
	destRect.x = pos->getX();
	destRect.y = pos->getY();
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