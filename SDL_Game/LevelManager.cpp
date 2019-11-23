#include "LevelManager.h"
#include <iostream>

LevelManager::LevelManager(SDL_Renderer *renderer) {
	currentLevel = 0;
	this->renderer = renderer;
	levels = std::vector<Level*>();
	levels.push_back(new Level(renderer, 1));
	levels.push_back(new Level(renderer, 2));
	levels.push_back(new Level(renderer, 3));
}

LevelManager::~LevelManager() {

}

void LevelManager::Update() {
	levels[currentLevel]->Update();
}

void LevelManager::Render() {
	levels[currentLevel]->Render();
}

void LevelManager::IncrementLevel() {
	if (currentLevel < levels.size() - 1) {
		currentLevel++;
	}
}

void LevelManager::ResetLevel() {
	levels[currentLevel]->Load(currentLevel);
}