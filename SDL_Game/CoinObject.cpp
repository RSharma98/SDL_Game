#include "CoinObject.h"

CoinObject::CoinObject() {

}

CoinObject::~CoinObject() {

}

void CoinObject::Initialise(SDL_Renderer* renderer, Vector2D* pos, Vector2D* scale) {
	spritePath = "Assets/Sprites/Dungeon Platformer Tileset/tileset.png";
	SDL_Rect source{ 48, 32, 16, 16 };
	this->sourceRect = source;
	GameObject::Initialise(renderer, pos, scale);
}