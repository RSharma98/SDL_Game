#include "LavaObject.h"

LavaObject::LavaObject() {
	
}

LavaObject::~LavaObject() {

}

void LavaObject::Initialise(SDL_Renderer *renderer, Vector2D *pos) {
	spritePath = "Assets/Sprites/Dungeon Platformer Tileset/tileset.png";
	SDL_Rect source{ 80, 144, 16, 16 };
	SDL_Rect dest{ pos->getX(), pos->getY(), 40, 40 };
	this->sourceRect = source;
	this->destRect = dest;
	GameObject::Initialise(renderer, pos);
}