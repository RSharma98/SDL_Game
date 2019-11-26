#include "Level.h"

	int levelArr1[10][10] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 1, 1, 6, 0, 0},
	{0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
	{0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
	{0, 0, 5, 1, 1, 1, 2, 1, 0, 0},
	{0, 0, 1, 1, 1, 1, 2, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

	int levelArr2[10][10] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 5, 1, 1, 1, 6, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 2, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 2, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 2, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

	int levelArr3[10][10] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 6, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 5, 1, 1, 1, 2, 1, 1, 0},
	{0, 1, 1, 1, 1, 2, 2, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

Level::Level(SDL_Renderer *renderer, int levelNumber){ 
	completedLevel = resetLevel = false;
	this->renderer = renderer;
	tilemap = new Tilemap(renderer);
	Load(levelNumber);
}

Level::~Level(){
}

void Level::Update() {
	tilemap->Update();
	completedLevel = tilemap->GetCompletedLevel();
	resetLevel = tilemap->GetResetLevel();
}

void Level::Render() {
	tilemap->Render();
}

void Level::Load(int levelNumber) {
	switch (levelNumber) {
	case 0:
		tilemap->Load(levelArr1);
		break;
	case 1:
		tilemap->Load(levelArr2);
		break;
	case 2:
		tilemap->Load(levelArr3);
		break;
	}
}

void Level::Reset() {
	tilemap->Reset();
}