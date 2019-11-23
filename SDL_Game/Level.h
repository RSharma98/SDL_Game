#ifndef LEVEL_H
#define LEVEL_H

#include "Tilemap.h"

class Level {
public:
	Level(SDL_Renderer *renderer);
	~Level();
	void Update();
	void Render();
	Tilemap* GetTilemap() { return tilemap; }

private:
	Tilemap* tilemap;
	SDL_Renderer* renderer;
	static int levelArr[10][10];
};
#endif // !LEVEL_H
