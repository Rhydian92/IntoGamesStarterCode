#include "Sprite.h"


Sprite::Sprite(SDL_Renderer* sdlRenderer, std::string pathToSurface, vec2 _spawnLocation) 
	: renderer(sdlRenderer), GameObject(_spawnLocation)
{
	SDL_Surface* surface = IMG_Load(pathToSurface.c_str());
	//surface = IMG_Load(pathToSurface.c_str());
	spriteW = surface->w;
	spriteH = surface->h;

	if (surface == NULL) {
		std::cerr << "Could not load surface at path: " << pathToSurface << std::endl;
		return;
	}

	visible = true;

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	
	SDL_FreeSurface(surface);
}

Sprite::Sprite(SDL_Renderer* sdlRenderer, std::string pathToSurface, vec2 _spawnLocation, bool _isGround)
	: renderer(sdlRenderer), GameObject(_spawnLocation)
{
	SDL_Surface* surface = IMG_Load(pathToSurface.c_str());
	//surface = IMG_Load(pathToSurface.c_str());
	spriteW = surface->w;
	spriteH = surface->h;

	if (surface == NULL) {
		std::cerr << "Could not load surface at path: " << pathToSurface << std::endl;
		return;
	}

	visible = true;

	texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);

	isGround = _isGround;
}


void Sprite::Render() {

	if (this->visible) {


		//destinationRect{ position.GetX(), position.GetY(), 32, 32 };
		//destinationRect = SDL_Rect(position.GetX(), position.GetY(), 32, 32);
		destinationRectangle.x = position.GetX();
		destinationRectangle.y = position.GetY();
		destinationRectangle.w = spriteW;
		destinationRectangle.h = spriteH;

		//// Draw our rect border.
		//SDL_RenderDrawRect(renderer, &destinationRectangle);

		// Collision
		//collisionRectangle.x = position.GetX() + ((spriteW / 2) - (10 / 2));
		//collisionRectangle.y = position.GetY() + ((spriteH / 2) - (10 / 2));
		//collisionRectangle.w = 10;
		//collisionRectangle.h = 10;
		//SDL_RenderDrawRect(renderer, &collisionRectangle);


		SDL_RenderCopy(renderer, texture, NULL, &destinationRectangle);

		// Use this instead of flipping.
		//SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_HORIZONTAL;
		//SDL_RenderCopyEx(renderer, texture, NULL, &destinationRectangle, 0, NULL, flip);




	}
}

bool Sprite::IsCollidingWith(Sprite& otherSprite)
{
	bool collision = SDL_HasIntersection(&collisionRectangle, &otherSprite.collisionRectangle);
	return collision;
}

bool Sprite::IsIntersectingWith(Sprite& sprite)
{
	return contactWithGround;
}

SDL_Rect Sprite::GetPlayerRect()
{
	return collisionRectangle;
}

vec2 Sprite::GetSize()
{
	return vec2(spriteW, spriteH);
}

void Sprite::SetRectPostion(vec2 _rectPostion)
{
	destinationRectangle.x = _rectPostion.GetX();
	destinationRectangle.y = _rectPostion.GetY();
}


