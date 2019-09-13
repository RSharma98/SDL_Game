#include <vector>
#include "BackgroundObject.h"

BackgroundObject::BackgroundObject() {

}

BackgroundObject::~BackgroundObject() {

}

void BackgroundObject::Initialise(SDL_Renderer* renderer, Vector2D* pos) {
	spritePath = "Assets/Sprites/Dungeon Platformer Backgroundset/Backgroundset.png";
	std::vector<SDL_Rect> sourceRects;
	sourceRects.push_back(SDL_Rect{ 0, 112, 16, 16 });
	sourceRects.push_back(SDL_Rect{ 16, 112, 16, 16 });
	SDL_Rect dest{ pos->getX(), pos->getY(), 40, 40 };
	int rand = Random(sourceRects.size() - 1);
	this->sourceRect = sourceRects.at(rand);
	this->destRect = dest;
	GameObject::Initialise(renderer, pos);
}

