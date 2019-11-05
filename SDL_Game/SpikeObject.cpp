#include "SpikeObject.h"

//Initialise a spike with a certain rotation angle
SpikeObject::SpikeObject(int rotation) {
	this->rotation = rotation;
}

SpikeObject::~SpikeObject() {

}

//Initialise the spike based on the angle
void SpikeObject::Initialise(SDL_Renderer* renderer, float posX, float posY, float scaleX, float scaleY) {
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
		sourceRect = SDL_Rect{ 32, 96, 16, 16 };
		break;
	}
	GameObject::Initialise(renderer, posX, posY, scaleX, scaleY);
}