#include "Level.h"

	int levelArr1[10][10] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 1, 6, 0, 0, 0},
	{0, 0, 0, 1, 2, 2, 1, 0, 0, 0},
	{0, 0, 0, 1, 2, 2, 1, 0, 0, 0},
	{0, 0, 0, 5, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

	int levelArr2[10][10] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 2, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 5, 1, 2, 1, 0, 0, 0},
	{0, 0, 0, 1, 1, 2, 6, 0, 0, 0},
	{0, 0, 0, 2, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

	int levelArr3[10][10] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 2, 1, 1, 1, 2, 0, 0, 0},
	{0, 0, 1, 1, 2, 1, 1, 0, 0, 0},
	{0, 0, 5, 1, 2, 1, 6, 0, 0, 0},
	{0, 0, 1, 1, 2, 1, 1, 0, 0, 0},
	{0, 0, 2, 1, 1, 1, 2, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

	int levelArr4[10][10] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 2, 6, 1, 0, 0},
	{0, 0, 1, 2, 1, 1, 2, 1, 0, 0},
	{0, 0, 1, 1, 2, 1, 1, 1, 0, 0},
	{0, 0, 2, 1, 5, 2, 2, 2, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

	int levelArr5[10][10] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 2, 6, 1, 1, 0, 0, 0},
	{0, 0, 0, 2, 2, 2, 1, 0, 0, 0},
	{0, 0, 0, 5, 2, 1, 1, 0, 0, 0},
	{0, 0, 0, 1, 2, 1, 2, 0, 0, 0},
	{0, 0, 0, 1, 1, 1, 2, 0, 0, 0},
	{0, 0, 0, 2, 2, 1, 2, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

	int levelArr6[10][10] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 2, 2, 1, 1, 2, 1, 0, 0},
	{0, 0, 6, 2, 5, 1, 2, 1, 0, 0},
	{0, 0, 1, 2, 2, 1, 1, 1, 0, 0},
	{0, 0, 1, 1, 2, 2, 1, 1, 0, 0},
	{0, 0, 2, 1, 1, 2, 2, 1, 0, 0},
	{0, 0, 2, 2, 1, 1, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

	int levelArr7[10][10] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 2, 2, 2, 1, 1, 1, 0, 0},
	{0, 0, 1, 2, 2, 1, 2, 2, 0, 0},
	{0, 0, 5, 2, 1, 1, 1, 1, 0, 0},
	{0, 0, 1, 2, 1, 2, 2, 6, 0, 0},
	{0, 0, 1, 2, 1, 1, 2, 2, 0, 0},
	{0, 0, 1, 1, 1, 2, 2, 2, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

	int levelArr8[10][10] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 2, 2, 6, 2, 0},
	{0, 0, 1, 2, 1, 2, 2, 1, 1, 0},
	{0, 0, 1, 2, 1, 1, 1, 2, 1, 0},
	{0, 0, 1, 2, 1, 2, 1, 1, 1, 0},
	{0, 0, 1, 2, 1, 1, 1, 2, 2, 0},
	{0, 0, 5, 2, 1, 2, 1, 2, 2, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

	int levelArr9[10][10] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 2, 1, 2, 1, 1, 2, 1, 1, 0},
	{0, 2, 1, 1, 1, 1, 1, 2, 1, 0},
	{0, 2, 1, 2, 1, 2, 1, 1, 2, 0},
	{0, 5, 1, 2, 1, 1, 2, 1, 1, 0},
	{0, 1, 2, 2, 2, 1, 2, 2, 6, 0},
	{0, 1, 2, 1, 2, 2, 2, 1, 1, 0},
	{0, 1, 1, 1, 1, 2, 1, 1, 2, 0},
	{0, 1, 1, 2, 1, 1, 1, 2, 2, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

	int levelArr10[10][10] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 2, 2, 2, 2, 2, 2, 2, 2, 0},
	{0, 2, 1, 1, 1, 1, 1, 1, 2, 0},
	{0, 2, 1, 2, 2, 2, 2, 1, 2, 0},
	{0, 2, 1, 1, 5, 2, 2, 1, 2, 0},
	{0, 2, 2, 2, 2, 6, 2, 1, 1, 0},
	{0, 2, 1, 1, 1, 1, 2, 2, 1, 0},
	{0, 2, 1, 2, 2, 2, 2, 2, 1, 0},
	{0, 2, 1, 1, 1, 1, 1, 1, 1, 0},
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
	case 3:
		tilemap->Load(levelArr4);
		break;
	case 4:
		tilemap->Load(levelArr5);
		break;
	case 5:
		tilemap->Load(levelArr6);
		break;
	case 6:
		tilemap->Load(levelArr7);
		break;
	case 7:
		tilemap->Load(levelArr8);
		break;
	case 8:
		tilemap->Load(levelArr9);
		break;
	case 9:
		tilemap->Load(levelArr10);
		break;
	}
}

void Level::Reset() {
	tilemap->Reset();
	completedLevel = false;
}