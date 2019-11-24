#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "Level.h"
#include "BlackOverlayObject.h"

class LevelManager {
public:
	LevelManager(SDL_Renderer* renderer);
	~LevelManager();
	void Update();
	void Render();
	void IncrementLevel();
	void ResetLevel();
	Tilemap* GetCurrentTilemap() { return levels[currentLevel]->GetTilemap(); }

private:
	bool incrementLevel;
	bool resetLevel;
	int currentLevel = 0;
	std::vector <Level*> levels;
	SDL_Renderer* renderer;
	BlackOverlayObject* blackOverlay;
};

#endif