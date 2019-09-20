#pragma once
#ifndef PLAYER_OBJECT_H
#define PLAYER_OBJECT_H

#include "GameObject.h"

class PlayerObject : public GameObject
{
public:
	PlayerObject();
	~PlayerObject();
	void Initialise(SDL_Renderer* renderer, float posX, float posY, float scaleX, float scaleY);
	void Update();
	void SetDir(int dir) { moveDir = dir; }

private:
	int moveDir;
	const int moveSpeed = 4;
	const int jumpHeight = 10;
	const int gravity = 10;
};

#endif // !PLAYER_OBJECT_H