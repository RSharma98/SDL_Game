#include <vector>
#include "BackgroundObject.h"

BackgroundObject::BackgroundObject() {

}

BackgroundObject::~BackgroundObject() {

}

void BackgroundObject::Initialise(SDL_Renderer* renderer, float posX, float posY, float scaleX, float scaleY) {
	spritePath = "Assets/Sprites/Dungeon Platformer Tileset/tileset.png";
	std::vector<SDL_Rect> sourceRects;
	sourceRects.push_back(SDL_Rect{ 0, 112, 16, 16 });
	sourceRects.push_back(SDL_Rect{ 16, 112, 16, 16 });
	int rand = Random(sourceRects.size() - 1);
	this->sourceRect = sourceRects.at(rand);
	GameObject::Initialise(renderer, posX, posY, scaleX, scaleY);
}

