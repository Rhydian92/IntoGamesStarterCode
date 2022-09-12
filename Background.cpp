#include "Background.h"

Background::Background(SDL_Renderer* renderer, std::string pathToSurface, vec2 _spawnLocation) :
	Sprite(renderer, pathToSurface, _spawnLocation)
{
	std::cout << "Background created.\nPosition set to " << _spawnLocation << std::endl;
}

void Background::Update(double deltaTime)
{
	//std::cout << "Background location: " << position;
	vec2 scroll = scrollDirection * scrollSpeed;

	//scroll.SetX((int)(scroll.GetX()));
	//scroll.SetY((int)(scroll.GetY()));

	// std::cout << position;
	Move(scroll);
}

void Background::Render()
{
	if (this->visible) {


		//destinationRect{ position.GetX(), position.GetY(), 32, 32 };
		//destinationRect = SDL_Rect(position.GetX(), position.GetY(), 32, 32);
		destinationRectangle.x = position.GetX();
		destinationRectangle.y = position.GetY();
		destinationRectangle.w = spriteW;
		destinationRectangle.h = spriteH;
		SDL_RenderDrawRect(renderer, &destinationRectangle);

		SDL_Rect bgr2Rect{ position.GetX()+spriteW, position.GetY(), spriteW, spriteH };

		if (position.GetX() <= -spriteW)
		{
			position = vec2(0, 0);
		}

		SDL_RenderCopy(renderer, texture, NULL, &destinationRectangle);
		SDL_RenderCopy(renderer, texture, NULL, &bgr2Rect);

	}
}
