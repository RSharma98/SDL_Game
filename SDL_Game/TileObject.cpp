#include <vector>
#include "TileObject.h"

TileObject::TileObject() {

}

TileObject::~TileObject() {

}

void TileObject::Initialise(SDL_Renderer* renderer, Vector2D* pos) {
	spritePath = "Assets/Sprites/Dungeon Platformer Tileset/tileset.png";
	std::vector<SDL_Rect> sourceRects;
	sourceRects.push_back(SDL_Rect{ 0, 144, 16, 16 });
	sourceRects.push_back(SDL_Rect{ 16, 144, 16, 16 });
	sourceRects.push_back(SDL_Rect{ 0, 128, 16, 16 });
	sourceRects.push_back(SDL_Rect{ 0, 80, 16, 16 });
	sourceRects.push_back(SDL_Rect{ 0, 64, 16, 16 });
	sourceRects.push_back(SDL_Rect{ 0, 48, 16, 16 });
	sourceRects.push_back(SDL_Rect{ 16, 48, 16, 16 });
	sourceRects.push_back(SDL_Rect{ 32, 48, 16, 16 });
	SDL_Rect dest{ pos->getX(), pos->getY(), 40, 40 };
	int rand = Random(sourceRects.size() - 1);
	this->sourceRect = sourceRects.at(rand);
	this->destRect = dest;
	GameObject::Initialise(renderer, pos);
}

