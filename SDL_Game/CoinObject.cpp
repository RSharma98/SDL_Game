#include "CoinObject.h"

CoinObject::CoinObject() {

}

CoinObject::~CoinObject() {

}

void CoinObject::Initialise(SDL_Renderer* renderer, Vector2D* pos) {
	spritePath = "Assets/Sprites/Dungeon Platformer Tileset/tileset.png";
	SDL_Rect source{ 48, 32, 16, 16 };
	SDL_Rect dest{ pos->getX(), pos->getY(), 40, 40 };
	this->sourceRect = source;
	this->destRect = dest;
	GameObject::Initialise(renderer, pos);
}