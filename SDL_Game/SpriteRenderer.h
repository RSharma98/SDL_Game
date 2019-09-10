#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include "SDL.h"
#include "SDL_image.h"

class SpriteRenderer {
public:
	SpriteRenderer();
	void Initialise(const char* path, SDL_Renderer* renderer, SDL_Rect sourceRect, SDL_Rect destinationRect);
	void Render(SDL_Renderer *renderer); 

private:
	SDL_Texture *sprite;
	SDL_Rect sourceRect, destinationRect;
};

#endif 