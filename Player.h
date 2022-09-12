#pragma once
#include "Sprite.h"
#include "InputSystem.h"

struct Bullet {
	int x, y;
};

class Player : public Sprite
{
public:
	enum Direction { UP, DOWN, LEFT, RIGHT };

	//Player();
	Player(SDL_Renderer* renderer, std::string pathToSurface, vec2 _spawnLocation);
	Player(SDL_Renderer* renderer, std::string pathToSurface, vec2 _spawnLocation, std::string pathToShadow);
	~Player();
	void HandleInput(SDL_Event& e);

	void SetHealth(int newHealth);
	void ReduceHealth(int healthReduction);
	int GetHealth();
	float GetMoveSpeed();
	
	void Update(double deltaTime, InputSystem& inputSystem);
	bool CheckGrounded(Sprite* sprite);

	void Render() override;

	void MoveShadow(double deltaTime);

private:
	int maxHealth = 100;
	int minHealth = 0;
	int health = 100;
	float moveSpeed = 400;

	Direction currentDirection;	
	vec2 respawn;
	bool shooting = false;
	
	bool isJumping = false;
	float defaultJumpVelocity = 400;
	float jumpVelocity = 400;
	float gravity = -908;


	float terminalVelocity = -1000; // We don't want out character to fall too fast.

	SDL_Surface shadowSurface;
	Sprite *shadowSprite = NULL;

	int shadowInset = 10;
	int shadowAdjustment;
	vec2 shadowPosition;

	SDL_Scancode jump = SDL_Scancode::SDL_SCANCODE_SPACE;

protected:
	//SDL_Scancode lastKeyPressed = SDL_Scancode::SDL_NUM_SCANCODES;
};