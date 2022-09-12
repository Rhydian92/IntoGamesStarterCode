#pragma once
#include "Sprite.h"

class Ground
{
public:
	Ground(SDL_Renderer* _renderer);
	void Render();
	SDL_Rect ground;
private:
	SDL_Renderer* renderer;
};