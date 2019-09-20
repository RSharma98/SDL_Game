#include "PlayerObject.h"
#include <iostream>

PlayerObject::PlayerObject() {
	moveDir = 0;
}

PlayerObject::~PlayerObject() {

}

void PlayerObject::Update() {
	float moveDist = moveSpeed * moveDir;
	std::cout << "X position: " << posX << '\n';
	posX += moveDist;
	std::cout << "X position: " << posX << '\n';
	GameObject::Update();
}

void PlayerObject::Initialise(SDL_Renderer* renderer, float posX, float posY, float scaleX, float scaleY) {
	spritePath = "Assets/Sprites/Dungeon Platformer Tileset/tileset.png";
	sourceRect = SDL_Rect{ 48, 144, 16, 16 };
	GameObject::Initialise(renderer, posX, posY, scaleX, scaleY);
}

