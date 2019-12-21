#include "LevelManager.h"
#include <iostream>

LevelManager::LevelManager(SDL_Renderer *renderer) {
	currentLevel = 0;
	incrementLevel = resetLevel = false;
	blackOverlay = new BlackOverlayObject();
	blackOverlay->Initialise(renderer, 640, 0, 640, 640);
	this->renderer = renderer;
	levels.push_back(new Level(renderer, 0));
	levels.push_back(new Level(renderer, 1));
	levels.push_back(new Level(renderer, 2));
	levels.push_back(new Level(renderer, 3));
	levels.push_back(new Level(renderer, 4));
	levels.push_back(new Level(renderer, 5));
	levels.push_back(new Level(renderer, 6));
	levels.push_back(new Level(renderer, 7));
	levels.push_back(new Level(renderer, 8));
	levels.push_back(new Level(renderer, 9));
}

LevelManager::~LevelManager() {

}

void LevelManager::Update() {
	levels[currentLevel]->Update();
	blackOverlay->Update();

	if (levels[currentLevel]->GetResetLevel()) resetLevel = true;
	if (levels[currentLevel]->GetCompletedLevel()) incrementLevel = true;

	if (incrementLevel ^ resetLevel) {
		if (!blackOverlay->IsBringingIn() && !blackOverlay->CompletedBringIn()) blackOverlay->BringIn();
		if (blackOverlay->CompletedBringIn() && !blackOverlay->IsBringingOut()) {
			if (incrementLevel) IncrementLevel();
			else ResetLevel();
			if(!completedGame) blackOverlay->BringOut();
			incrementLevel = resetLevel = false;
		}
	}
}

void LevelManager::Render() {
	levels[currentLevel]->Render();
	blackOverlay->Render(renderer);
}

void LevelManager::IncrementLevel() {
	if (currentLevel < levels.size() - 1) {
		currentLevel++;
	}
	else {
		completedGame = true;
	}
}

void LevelManager::ResetLevel() {
	levels[currentLevel]->Reset();
}

void LevelManager::ResetGame(){
	currentLevel = 0;
	completedGame = false;
	for (int i = 0; i < levels.size(); i++) {
		levels.at(i)->Reset();
	}
	blackOverlay->BringOut();
}