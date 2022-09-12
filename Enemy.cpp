#include "Enemy.h"

Enemy::Enemy(SDL_Renderer* renderer, std::string pathToSurface, vec2 _spawnLocation) :
	Sprite(renderer, pathToSurface, _spawnLocation)
{
	std::cout << "An enemy has been created.\nPosition set to (" << _spawnLocation.GetX() << ", " << _spawnLocation.GetY() << ")." << std::endl;
}
