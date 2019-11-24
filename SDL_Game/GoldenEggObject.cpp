#include "GoldenEggObject.h"

GoldenEggObject::GoldenEggObject() {

}

GoldenEggObject::~GoldenEggObject() {

}

void GoldenEggObject::Initialise(SDL_Renderer* renderer, float posX, float posY, float scaleX, float scaleY) {
	spritePath = "Assets/Sprites/Golden_Egg.png";
	sourceRect = SDL_Rect{ 0, 0, 16, 16 };
	GameObject::Initialise(renderer, posX, posY, scaleX, scaleY);
}