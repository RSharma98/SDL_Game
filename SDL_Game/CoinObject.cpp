#include "CoinObject.h"

CoinObject::CoinObject() {

}

CoinObject::~CoinObject() {

}

void CoinObject::Initialise(SDL_Renderer* renderer, float posX, float posY, float scaleX, float scaleY) {
	spritePath = "Assets/Sprites/Dungeon Platformer Tileset/tileset.png";
	SDL_Rect source{ 48, 32, 16, 16 };
	this->sourceRect = source;
	GameObject::Initialise(renderer, posX, posY, scaleX, scaleY);
}