#pragma once
#include "Sprite.h"

class Enemy : public Sprite
{
public:
	Enemy(SDL_Renderer* renderer, std::string pathToSurface, vec2 _spawnLocation);

private:

protected:

};