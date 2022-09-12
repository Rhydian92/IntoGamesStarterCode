#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include "Player.h"


class UI
{
public:
	UI(SDL_Renderer* _renderer, Player* _player);
	void Render();
	//void Update();

	void HandleMouse(SDL_Event& e);

	~UI();

private:
	SDL_Renderer* renderer;
	Player* player;

	TTF_Font* font;
	const char* fontPath = "assets/Fonts/ComicNeue-Bold.ttf";

	// Button variable.
	SDL_Rect fontRectangle{ 12, 9, 50, 19 };
};