#pragma once

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "Player.h"
#include "Enemy.h"
#include "Collectable.h"
#include "UI.h"
#include "TiledMap.h"

#include "InputSystem.h"
#include "Background.h"

class GameLoop
{
public:
	void Initialise();
	void LoadContent();
	bool Update();
	void Render();
	void UnloadContent();
	void Quit();

private:
	
	// Game objects
	InputSystem* inputSystem;
	UI* ui;
	//TiledMap* tiledMap;
	
	Player* player;
	Enemy* enemy;
	Collectable* collectable;
	//Sprite* backgroundImage;
	Background* background;

	// SDL pointers
	SDL_Window* window;
	SDL_Renderer* renderer;

	// Collectable timer
	double collectableTimer = 0;
	

	// Game logic
	double deltaTime = 0;
	double lastFrameTime = 0;
	double currentFrameTime = 0;

	vec2 windowSize = vec2(640, 320);
};

