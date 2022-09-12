#include "Collectable.h"

Collectable::Collectable(SDL_Renderer* renderer, std::string filePath, vec2 _position)
	: Sprite(renderer, filePath, _position)
{
}