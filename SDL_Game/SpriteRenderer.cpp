#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer() {}

void SpriteRenderer::Initialise(const char* path, SDL_Renderer *renderer, SDL_Rect sourceRect, SDL_Rect destinationRect) {
	SDL_Surface* surface = IMG_Load(path);
	sprite = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	this->sourceRect = sourceRect;
	this->destinationRect = destinationRect;
}

void SpriteRenderer::Render(SDL_Renderer *renderer, SDL_Rect destRect) {
	SDL_RenderCopy(renderer, sprite, &sourceRect, &destRect);
}