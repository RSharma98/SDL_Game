#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer() {}

//Initialise a sprite rendererer so an image can be loaded based on the image path and specified rects
void SpriteRenderer::Initialise(const char* path, SDL_Renderer *renderer, SDL_Rect sourceRect, SDL_Rect destinationRect) {
	SDL_Surface* surface = IMG_Load(path);
	sprite = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	this->sourceRect = sourceRect;
	this->destinationRect = destinationRect;
	renderSprite = true;
}

//Render the sprite
void SpriteRenderer::Render(SDL_Renderer *renderer, SDL_Rect destRect) {
	if(renderSprite) SDL_RenderCopy(renderer, sprite, &sourceRect, &destRect);
}