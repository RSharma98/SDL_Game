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
	void MoveHorizontal(int dir);
	void MoveVertical(int dir);

private:
	const int moveSpeed = 64;
};

#endif // !PLAYER_OBJECT_H