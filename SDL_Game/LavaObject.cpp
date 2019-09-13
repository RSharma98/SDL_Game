#include "LavaObject.h"

LavaObject::LavaObject() {
	
}

LavaObject::~LavaObject() {

}

void LavaObject::Initialise(SDL_Renderer *renderer, Vector2D *pos, Vector2D* scale) {
	spritePath = "Assets/Sprites/Dungeon Platformer Tileset/tileset.png";
	SDL_Rect source{ 80, 144, 16, 16 };
	this->sourceRect = source;
	GameObject::Initialise(renderer, pos, scale);
}