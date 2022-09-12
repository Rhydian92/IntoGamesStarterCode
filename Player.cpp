#include <iostream>
#include "Player.h"

Player::Player(SDL_Renderer* renderer, std::string pathToSurface, vec2 _spawnLocation) :
	Sprite(renderer, pathToSurface, _spawnLocation)
{
	std::cout << "A player has been created.\nPosition set to (" << _spawnLocation.GetX() << ", " << _spawnLocation.GetY() << ")." << std::endl;
}

Player::Player(SDL_Renderer* renderer, std::string pathToSurface, vec2 _spawnLocation, std::string pathToShadow) :
	Sprite(renderer, pathToSurface, _spawnLocation),
	shadowSprite(new Sprite(renderer, pathToShadow, _spawnLocation))
{
	std::cout << "A player with shadow has been created.\nPosition set to " << position;
	shadowSprite->position.SetX(position.GetX());
	shadowSprite->position.SetY(position.GetY() + spriteH - shadowAdjustment);
}

Player::~Player()
{
	if (shadowSprite != NULL)
		delete shadowSprite;
}

void Player::SetHealth(int newHealth)
{
	health = newHealth;
}

void Player::ReduceHealth(int healthReduction)
{
	health -= healthReduction;

	if (health >= maxHealth) {
		health = maxHealth;
	}
	else if (health <= minHealth) {
		health = minHealth;
	}
}

int Player::GetHealth()
{
	return health;
}

float Player::GetMoveSpeed()
{
	return moveSpeed;
}

void Player::Update(double deltaTime, InputSystem& inputSystem)
{	
	Move(inputSystem.GetMoveAxis() * moveSpeed * deltaTime);
	if (inputSystem.GetButtonDown() == jump)
	{
		isJumping = true;
	}	
	//ADD THIS IN FOR ANIM
	//Sprite::Update(deltaTime);
	
	// --- SHADOW POSITION ---
	if (isJumping) {
		shadowPosition = vec2(position.GetX(), shadowPosition.GetY());
	}
	else {
		shadowPosition = vec2(position.GetX(), position.GetY() + spriteH - shadowInset);
	}
	shadowSprite->position = shadowPosition;
	// --- --- ---

	if (isJumping) {

		Move(vec2::Up() * jumpVelocity * deltaTime);
		//if (shadowSprite != NULL)
		//{
		//	//MoveShadow(deltaTime);
		//}

		if (jumpVelocity > -defaultJumpVelocity)
		{
			jumpVelocity += gravity * deltaTime;
			if (jumpVelocity < -defaultJumpVelocity)
				jumpVelocity = -defaultJumpVelocity; // Protection from overshoot.
			std::cout << jumpVelocity << "\n";
		}
		else// if (jumpVelocity <= -jumpVelocity)
		{
			jumpVelocity = defaultJumpVelocity;
			isJumping = false;
		}
	}
}

void Player::MoveShadow(double deltaTime)
{
	//shadowSprite->position = shadowPosition;
	shadowSprite->Move(vec2::Down() * jumpVelocity * deltaTime);
}

bool Player::CheckGrounded(Sprite* sprite)
{
	//bool collision = SDL_HasIntersection(&destinationRectangle, &sprite)
	//SDL_Rect collider = sprite->GetPlayerRect();
	return true;
}

void Player::Render()
{
	if (this->visible) {


		//destinationRect{ position.GetX(), position.GetY(), 32, 32 };
		//destinationRect = SDL_Rect(position.GetX(), position.GetY(), 32, 32);
		destinationRectangle.x = position.GetX();
		destinationRectangle.y = position.GetY();
		destinationRectangle.w = spriteW;
		destinationRectangle.h = spriteH;
		//SDL_RenderDrawRect(renderer, &destinationRectangle);

		// GO SHADOW_ROOT IS SAME AS PLAYER MINUS OUR OFFSET
		// >>> SHADOW_POS = SHADOW_ROOT
		// IF JUMPING
		// >> >> SHADOW X = FROG X, SHADOW Y = FROG Y - OFFSET

		//shadowPosition = vec2(position.GetX(), position.GetY() + spriteH - shadowInset);
		//shadowSprite->position = shadowPosition;
		shadowSprite->Render();
		SDL_RenderCopy(renderer, texture, NULL, &destinationRectangle);

	}
}
