#include "BlackOverlayObject.h"

BlackOverlayObject::BlackOverlayObject() {
	bringIn = bringOut = false;
	completedBringIn = completedBringOut = false;
}

BlackOverlayObject::~BlackOverlayObject() {

}


void BlackOverlayObject::Initialise(SDL_Renderer* renderer, float posX, float posY, float scaleX, float scaleY) {
	spritePath = "Assets/black.png";
	SDL_Rect source{ 0, 100, 100, 100 };
	this->sourceRect = source;
	GameObject::Initialise(renderer, posX, posY, scaleX, scaleY);
}

void BlackOverlayObject::Update() {
	if(bringIn){
		if (posX < 0) {
			posX += 640 * Time::GetDeltaTime();
		}
		else {
			completedBringIn = true;
			bringIn = false;
			posX = 0;
		}
	}
	if (bringOut) {
		if(posX < 640){
			posX += 640 * Time::GetDeltaTime();
		}
		else {
			completedBringOut = true;
			bringOut = false;
			posX = 640;
		}
	}
	GameObject::Update();
}

void BlackOverlayObject::BringIn() {
	bringIn = true;
	completedBringIn = false;
	completedBringOut = false;
	bringOut = false;
	posX = -640;
}

void BlackOverlayObject::BringOut() {
	bringIn = false;
	bringOut = true;
	completedBringIn = false;
	completedBringOut = false;
	posX = 0;
}