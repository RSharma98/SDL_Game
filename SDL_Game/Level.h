#ifndef LEVEL_H
#define LEVEL_H

#include "Tilemap.h"

class Level {
public:
	Level(SDL_Renderer *renderer, int levelNumber);
	~Level();
	void Update();
	void Render();
	void Load(int levelNumber);
	void Reset();
	Tilemap* GetTilemap() { return tilemap; }
	bool GetResetLevel() { return resetLevel; }
	bool GetCompletedLevel() { return completedLevel; }

protected:
	Tilemap* tilemap;
	SDL_Renderer* renderer;
	bool resetLevel;
	bool completedLevel;
};
#endif // !LEVEL_H
