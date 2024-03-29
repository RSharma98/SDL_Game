#include <vector>
#include "TileObject.h"

TileObject::TileObject() {

}

TileObject::~TileObject() {

}

//Initialise the tile based on the tile type
//This works by pushing all the possible source rectangles to a vector and picking one at random.
//The type of tile determines if it is a regular tile the player can walk on or if it's a wall tile
void TileObject::Initialise(SDL_Renderer* renderer, float posX, float posY, float scaleX, float scaleY, TileType tileType) {
	spritePath = "Assets/Sprites/Dungeon_Tileset.png";
	std::vector<SDL_Rect> sourceRects;
	switch (tileType)
	{
	case Normal:
		sourceRects.push_back(SDL_Rect{ 96, 0, 16, 16 });
		sourceRects.push_back(SDL_Rect{ 96, 16, 16, 16 });
		sourceRects.push_back(SDL_Rect{ 96, 32, 16, 16 });
		sourceRects.push_back(SDL_Rect{ 112, 0,  16, 16 });
		sourceRects.push_back(SDL_Rect{ 112, 16, 16, 16 });
		sourceRects.push_back(SDL_Rect{ 112, 32, 16, 16 });
		sourceRects.push_back(SDL_Rect{ 128, 0, 16, 16 });
		sourceRects.push_back(SDL_Rect{ 128, 16, 16, 16 });
		sourceRects.push_back(SDL_Rect{ 128, 32, 16, 16 });
		break;
	case Top:
		sourceRects.push_back(SDL_Rect{ 16, 0, 16, 16 });
		sourceRects.push_back(SDL_Rect{ 32, 0, 16, 16 });
		sourceRects.push_back(SDL_Rect{ 48, 0, 16, 16 });
		sourceRects.push_back(SDL_Rect{ 64, 0,  16, 16 });
		break;
	case Bottom:
		sourceRects.push_back(SDL_Rect{ 16, 64, 16, 16 });
		sourceRects.push_back(SDL_Rect{ 32, 64, 16, 16 });
		sourceRects.push_back(SDL_Rect{ 48, 64, 16, 16 });
		sourceRects.push_back(SDL_Rect{ 64, 64,  16, 16 });
		break;
	case TopLeft:
		sourceRects.push_back(SDL_Rect{ 0, 0, 16, 16 });
		break;
	case TopRight:
		sourceRects.push_back(SDL_Rect{ 80, 0, 16, 16 });
		break;
	case BottomLeft:
		sourceRects.push_back(SDL_Rect{ 0, 64, 16, 16 });
		break;
	case BottomRight:
		sourceRects.push_back(SDL_Rect{ 80, 64, 16, 16 });
		break;
	case Left:
		sourceRects.push_back(SDL_Rect{ 0, 16, 16, 16 });
		sourceRects.push_back(SDL_Rect{ 0, 32, 16, 16 });
		sourceRects.push_back(SDL_Rect{ 0, 48, 16, 16 });
		break;
	case Right:
		sourceRects.push_back(SDL_Rect{ 80, 16, 16, 16 });
		sourceRects.push_back(SDL_Rect{ 80, 32, 16, 16 });
		sourceRects.push_back(SDL_Rect{ 80, 48, 16, 16 });
		break;
	default:
		break;
	}
	int rand = Random(sourceRects.size() - 1);
	this->sourceRect = sourceRects.at(rand);
	GameObject::Initialise(renderer, posX, posY, scaleX, scaleY);
}

