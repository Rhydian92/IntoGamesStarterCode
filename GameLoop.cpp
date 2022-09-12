#include "GameLoop.h"
//#include "Sprite.h"

void GameLoop::Initialise()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		return;
	}
	else {
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			std::cerr << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
			return;
		}

		//window = SDL_CreateWindow("IntoGames", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 256, SDL_WINDOW_SHOWN);
		window = SDL_CreateWindow("IntoGames", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowSize.GetX(), windowSize.GetY(), SDL_WINDOW_SHOWN);

		if (window == NULL) {
			std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
			return;
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == NULL) {
			std::cerr << "SDL could not initialize renderer! SDL_Error: " << SDL_GetError() << std::endl;
		}
	}

}

void GameLoop::LoadContent()
{
	//backgroundImage = new Sprite(renderer, "assets/Sprites/Background_32x32_20x10.png", vec2::Zero());
	background = new Background(renderer, "assets/Sprites/Background_32x32_20x10.png", vec2::Zero());

	player = new Player(renderer, "assets/Sprites/Frog.png", vec2(10,160), "assets/Sprites/FrogShadow.png");
	enemy = new Enemy(renderer, "assets/images/enemy.png", vec2(100,100));
	collectable = new Collectable(renderer, "assets/Items/Fruits/SingleMelon.png", vec2(200, 100));
	ui = new UI(renderer, player);
	//tiledMap = new TiledMap(renderer, "assets/Sprites/scifitiles_32x32_14x6.png");

	inputSystem = new InputSystem();

}

bool GameLoop::Update()
{
	SDL_Delay(20);

	SDL_Event e;
	/* Poll for events. SDL_PollEvent() returns 0 when there are no  */
	/* more events on the event queue, our while loop will exit when */
	/* that occurs.                                                  */

	while (SDL_PollEvent(&e) != 0) {

		if (e.type == SDL_QUIT) {
			return false;
		}

		// Check the SDL event in the input system.
		inputSystem->CheckEvent(e);
		
		ui->HandleMouse(e); // REMINDER - MOVE THIS TO INPUT SYSTEM CLASS

	}

	// --- UPDATE GAME STATE BY CALLING UPDATE METHODS ---
	background->Update(deltaTime);
	player->Update(deltaTime, *inputSystem);
	//player->IsCollidingWith(*enemy); // returns a bool
	// --- --- --- --- --- --- --- --- --- --- --- --- ---
	
	if (player->IsCollidingWith(*collectable))
	{
		std::cout << "Collectable picked up!!" << std::endl;
		player->ReduceHealth(-5);
	}	
	

	// --- CALCULATE DELTA TIME (USED FOR UPDATE METHODS) ---
	lastFrameTime = currentFrameTime;
	currentFrameTime = SDL_GetPerformanceCounter();
	deltaTime = (double)((currentFrameTime - lastFrameTime) / (double)SDL_GetPerformanceFrequency());


	//tiledMap->CheckCollision(player);

	return true;
}



void GameLoop::Render()
{
	// Change the background colour here
	SDL_SetRenderDrawColor(renderer, 60, 60, 60, 0);
	SDL_RenderClear(renderer);

	// Render any other object here.
	//backgroundImage->Render();
	background->Render();
	//tiledMap->Render();
	//enemy->Render();
	player->Render();
	//collectable->Render();
	ui->Render();

	SDL_RenderPresent(renderer);
}

void GameLoop::UnloadContent()
{
	delete inputSystem;
	delete ui;
	//delete tiledMap;
	delete player;
	delete enemy;
	delete collectable;
}

void GameLoop::Quit()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	window = NULL;
	SDL_Quit();
	IMG_Quit();
}