#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

#include "GameObject.h"



class Sprite : public GameObject {
public:
	Sprite(SDL_Renderer* renderer, std::string pathToSurface, vec2 _spawnLocation);
	Sprite(SDL_Renderer* renderer, std::string pathToSurface, vec2 _spawnLocation, bool _isGround);
	virtual ~Sprite() {}

	virtual void Render();
	//virtual void Update(double deltaTime);
	
	void SetVisible(bool visible) { this->visible = visible; }
	bool GetVisible() const { return visible; }

	bool IsCollidingWith(Sprite& sprite);
	bool IsIntersectingWith(Sprite& sprite);

	SDL_Rect GetPlayerRect();
	vec2 GetSize();

	void SetRectPostion(vec2 _rectPostion);

private:
	//SDL_Rect destinationRectangle;
	//SDL_Rect collisionRectangle;
	//SDL_Texture* texture;
	//bool visible;

	////SDL_Surface* surface;
	//int spriteW, spriteH;

	//bool contactWithGround;
	//bool isGround = false;


protected:
	SDL_Renderer* renderer;
	SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE;

	SDL_Rect destinationRectangle;
	SDL_Rect collisionRectangle;
	SDL_Texture* texture;
	bool visible;

	//SDL_Surface* surface;
	int spriteW, spriteH;

	bool contactWithGround;
	bool isGround = false;
};