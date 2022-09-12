#pragma once
#include "Sprite.h"



class Background : public Sprite
{
public:
	Background(SDL_Renderer* renderer, std::string pathToSurface, vec2 _spawnLocation);

	void Update(double deltaTime);
	void Render() override;


private:
	vec2 scrollDirection = vec2(-1, 0);
	float scrollSpeed = 4;
	vec2 scroll;
};

