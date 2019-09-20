#include <vector>
#include "TileObject.h"

TileObject::TileObject() {

}

TileObject::~TileObject() {

}

void TileObject::Initialise(SDL_Renderer* renderer, float posX, float posY, float scaleX, float scaleY) {
	spritePath = "Assets/Sprites/Dungeon Platformer Tileset/tileset.png";
	std::vector<SDL_Rect> sourceRects;
	sourceRects.push_back(SDL_Rect{ 0, 128, 16, 16 });
	sourceRects.push_back(SDL_Rect{ 0, 80, 16, 16 });
	sourceRects.push_back(SDL_Rect{ 0, 64, 16, 16 });
	sourceRects.push_back(SDL_Rect{ 0, 48, 16, 16 });
	sourceRects.push_back(SDL_Rect{ 16, 48, 16, 16 });
	sourceRects.push_back(SDL_Rect{ 32, 48, 16, 16 });
	int rand = Random(sourceRects.size() - 1);
	this->sourceRect = sourceRects.at(rand);
	GameObject::Initialise(renderer, posX, posY, scaleX, scaleY);
}

