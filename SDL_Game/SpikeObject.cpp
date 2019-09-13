#include "SpikeObject.h"

SpikeObject::SpikeObject(int rotation) {
	this->rotation = rotation;
}

SpikeObject::~SpikeObject() {

}

void SpikeObject::Initialise(SDL_Renderer* renderer, Vector2D* pos) {
	spritePath = "Assets/Sprites/Dungeon Platformer Tileset/tileset.png";
	switch (rotation) {
	case 0:
		sourceRect = SDL_Rect{32, 96, 16, 16};
		break;
	case 1:
		sourceRect = SDL_Rect{ 16, 128, 16, 16 };
		break;
	case 2:
		sourceRect = SDL_Rect{ 32, 128, 16, 16 };
		break;
	case 3:
		sourceRect = SDL_Rect{ 48, 128, 16, 16 };
		break;
	default:
		break;
	}
	SDL_Rect dest{ pos->getX(), pos->getY(), 40, 40 };
	this->destRect = dest;
	GameObject::Initialise(renderer, pos);
}