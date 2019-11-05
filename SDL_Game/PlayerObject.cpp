#include "PlayerObject.h"

PlayerObject::PlayerObject() {

}

PlayerObject::~PlayerObject(){

}

void PlayerObject::Initialise(SDL_Renderer* renderer, float posX, float posY, float scaleX, float scaleY) {
	spritePath = "Assets/Sprites/Dungeon Platformer Tileset/tileset.png";
	sourceRect = SDL_Rect{ 48, 144, 16, 16 };
	GameObject::Initialise(renderer, posX, posY, scaleX, scaleY);
}

void PlayerObject::MoveVertical(int dir) {
	posY -= moveSpeed * dir;
	GameObject::Update();
}

void PlayerObject::MoveHorizontal(int dir) {
	posX += moveSpeed * dir;
	GameObject::Update();
}

