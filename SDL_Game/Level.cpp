#include "Level.h"

int Level::levelArr[10][10] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 8, 1, 1, 1, 2, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 2, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

Level::Level(SDL_Renderer *renderer){ 
	this->renderer = renderer;
	tilemap = new Tilemap(renderer);
	tilemap->Load(levelArr);
}

Level::~Level(){
	delete[] tilemap;
	delete[] levelArr;
}

void Level::Update() {
	tilemap->Update();
}

void Level::Render() {
	tilemap->Render();
}