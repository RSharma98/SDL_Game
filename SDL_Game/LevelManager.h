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
	void ResetGame();
	Tilemap* GetCurrentTilemap() { return levels[currentLevel]->GetTilemap(); }
	bool GetCompletedLevel() { return completedGame; }

private:
	bool incrementLevel;
	bool resetLevel;
	bool completedGame;
	int currentLevel = 0;
	std::vector <Level*> levels;
	SDL_Renderer* renderer;
	BlackOverlayObject* blackOverlay;
};

#endif