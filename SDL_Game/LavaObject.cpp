#include "LavaObject.h"

LavaObject::LavaObject() {
	
}

LavaObject::~LavaObject() {

}

void LavaObject::Initialise(SDL_Renderer *renderer, float posX, float posY, float scaleX, float scaleY) {
	spritePath = "Assets/Sprites/Lava.png";
	SDL_Rect source{ 0, 0, 16, 16 };
	this->sourceRect = source;
	GameObject::Initialise(renderer, posX, posY, scaleX, scaleY);
}