#include "UI.h"

UI::UI(SDL_Renderer* _renderer, Player* _player) {
	renderer = _renderer;
	player = _player;

	int error = TTF_Init();
	if (error == -1) {
		std::cout << "Could not init SDL ttf." << std::endl;
	}
	
	font = TTF_OpenFont(fontPath, 24);
}

void UI::Render()
{
	SDL_Color bgr_c{ 255, 0, 0, 255 };
	SDL_Color fgr_c{ 0, 255, 0, 255 };


	


	SDL_Color border_c{ 0, 0, 0, 255 };

	int health = player->GetHealth();
	float relativeHealth = (float)health;
	relativeHealth /= 100;

	int currentHealthLength = (int)(150 * relativeHealth);

	SDL_SetRenderDrawColor(renderer, border_c.r, border_c.g, border_c.b, border_c.a);
	SDL_Rect border{ 8, 8, 154, 24 };
	SDL_RenderFillRect(renderer, &border);

	SDL_SetRenderDrawColor(renderer, bgr_c.r, bgr_c.g, bgr_c.b, bgr_c.a);
	SDL_Rect bgrBar{ 10, 10, 150, 20 };
	SDL_RenderFillRect(renderer, &bgrBar);

	SDL_SetRenderDrawColor(renderer, fgr_c.r, fgr_c.g, fgr_c.b, fgr_c.a);
	SDL_Rect fgrBar{ 10, 10, currentHealthLength, 20 };
	SDL_RenderFillRect(renderer, &fgrBar);

	// TEXT
	SDL_Color bgr = SDL_Color{ 255, 255, 255, 255 };
	SDL_Color fgr = SDL_Color{ 255, 0, 0, 255 };
	// Use Shaded for text with background.
	//SDL_Surface* fontImage = TTF_RenderText_Shaded(font, "Lemons: ", fgr, bgr);
	SDL_Surface* fontImage = TTF_RenderText_Blended(font, "Health", fgr);
	SDL_Texture* fontTexture = SDL_CreateTextureFromSurface(renderer, fontImage);
	//SDL_Rect fontRectangle{ 300, 10, 100, 20 };
	SDL_RenderCopy(renderer, fontTexture, NULL, &fontRectangle);
	SDL_FreeSurface(fontImage);
	SDL_DestroyTexture(fontTexture);

}

void UI::HandleMouse(SDL_Event& e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN) {
		int mouseX, mouseY;
		SDL_GetMouseState(&mouseX, &mouseY);
		std::cout << mouseX << ", " << mouseY << std::endl;

		SDL_Point point = SDL_Point{ mouseX, mouseY };
		bool lemonButtonClicked = SDL_PointInRect(&point, &fontRectangle);
		if (lemonButtonClicked){
			std::cout << "Lemons\n";
			}
	}
}

UI::~UI()
{
	TTF_CloseFont(font);
	TTF_Quit();
}
