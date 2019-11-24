#include "LevelManager.h"
#include <iostream>

LevelManager::LevelManager(SDL_Renderer *renderer) {
	currentLevel = 0;
	incrementLevel = resetLevel = false;
	blackOverlay = new BlackOverlayObject();
	blackOverlay->Initialise(renderer, 640, 0, 640, 640);
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
	blackOverlay->Update();
	std::cout << "Current Level: " << currentLevel << '\n';

	if (levels[currentLevel]->GetResetLevel()) resetLevel = true;

	if (incrementLevel ^ resetLevel) {
		if (!blackOverlay->IsBringingIn() && !blackOverlay->CompletedBringIn()) blackOverlay->BringIn();
		if (blackOverlay->CompletedBringIn() && !blackOverlay->IsBringingOut()) {
			if (incrementLevel) IncrementLevel();
			else ResetLevel();
			blackOverlay->BringOut();
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
}

void LevelManager::ResetLevel() {
	levels[currentLevel]->Reset();
}