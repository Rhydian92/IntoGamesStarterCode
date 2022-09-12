#include "Ground.h"

Ground::Ground(SDL_Renderer* _renderer) : renderer(_renderer)
{
}

void Ground::Render()
{
	int screenW, screenH;
	SDL_GetRendererOutputSize(renderer, &screenW, &screenH);
	ground = SDL_Rect{ 0, screenH - 50, screenW, 50 };

	SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255);
	//SDL_RenderFillRect(renderer, &ground);
	SDL_RenderDrawRect(renderer, &ground);
}