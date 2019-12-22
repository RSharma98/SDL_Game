#include "SpikeObject.h"

//Initialise a spike with a certain rotation angle
SpikeObject::SpikeObject() {

}

SpikeObject::~SpikeObject() {

}

//Initialise the spike based on the angle
void SpikeObject::Initialise(SDL_Renderer* renderer, float posX, float posY, float scaleX, float scaleY) {
	spritePath = "Assets/Sprites/Spikes.png";
	sourceRect = SDL_Rect{ 0, 0, 16, 16 };
	GameObject::Initialise(renderer, posX, posY, scaleX, scaleY);
}