#include "InputSystem.h"
#include <iostream>

void InputSystem::CheckEvent(SDL_Event& event)
{
	switch (event.key.keysym.scancode)
	{
	case SDL_SCANCODE_W:
		if (event.type == SDL_KEYDOWN)
		{
			moveUp = -1;
		}
		else if (event.type == SDL_KEYUP)
		{
			moveUp = 0;
		}
		break;

	case SDL_SCANCODE_S:
		if (event.type == SDL_KEYDOWN)
		{
			moveDown = 1;
		}
		else if (event.type == SDL_KEYUP)
		{
			moveDown = 0;
		}
		break;

	case SDL_SCANCODE_A:
		if (event.type == SDL_KEYDOWN)
		{
			moveLeft = -1;
		}
		else if (event.type == SDL_KEYUP)
		{
			moveLeft = 0;
		}
		break;

	case SDL_SCANCODE_D:
		if (event.type == SDL_KEYDOWN)
		{
			moveRight = 1;
		}
		else if (event.type == SDL_KEYUP)
		{
			moveRight = 0;
		}
		break;

	case SDL_SCANCODE_SPACE:
		if (event.type == SDL_KEYDOWN)
		{
			buttonDown = SDL_SCANCODE_SPACE;
		}
		else if (event.type == SDL_KEYUP)
		{
			buttonDown = nullButton;
		}
		break;

	default:
		//std::cout << "Key pressed not a player option.\n";
		break;
	}

	int moveY = moveUp + moveDown;
	int moveX = moveLeft + moveRight;
	rawMoveAxis = vec2(moveX, moveY);

	//std::cout << buttonDown << "\n";
}

vec2 InputSystem::GetRawMoveAxis()
{
	return rawMoveAxis;
}

vec2 InputSystem::GetMoveAxis()
{
	moveAxis = rawMoveAxis.Normalized();
	return moveAxis;
}

SDL_Scancode InputSystem::GetButtonDown()
{
	return buttonDown;
}
