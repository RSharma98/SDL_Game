#include "GameObject.h"
#include <iostream>

GameObject::GameObject() {
	destRect = sourceRect = SDL_Rect{ 0, 0, 0, 0 };
}

GameObject::~GameObject() {

}

//This function intialises the object by rendering a sprite based on the specified values
void GameObject::Initialise(SDL_Renderer* renderer, float posX, float posY, float scaleX, float scaleY) {
	spriteRenderer = new SpriteRenderer();
	this->posX = posX;
	this->posY = posY;
	this->scaleX = scaleX;
	this->scaleY = scaleY;

	destRect.x = posX;
	destRect.y = posY;
	destRect.w = scaleX;
	destRect.h = scaleY;
	spriteRenderer->Initialise(spritePath, renderer, sourceRect, destRect);
}

//Update moves the sprite as needed
void GameObject::Update() {
	destRect.x = posX;
	destRect.y = posY;
	destRect.w = scaleX;
	destRect.h = scaleY;
	//Todo, update sprite renderer values based on object's transform
}

//This function renders the sprite (obviously)
void GameObject::Render(SDL_Renderer *renderer) {
	spriteRenderer->Render(renderer, destRect);
}

//This function generates a random number between zero and max
int GameObject::Random(int max){
	static bool first = true;
	if (first)
	{
		srand(time(NULL)); //seeding for the first time only!
		first = false;
	}
	return rand() % (max + 1);
}