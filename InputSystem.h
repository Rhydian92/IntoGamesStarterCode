#pragma once
#include <SDL.h>
#include "InputSystem.h"
#include "vec2.h"

class InputSystem
{
public:
	void CheckEvent(SDL_Event &event);

	vec2 GetRawMoveAxis(); // Returns an input axis that can be imagined as a square.
	vec2 GetMoveAxis();	// Returns an input axis that can be imagined as a circle.

	SDL_Scancode GetButtonDown();

private:
	// Can implement this for a comparison if we want multiple key bindings.
	//SDL_Scancode key = SDL_Scancode::SDL_NUM_SCANCODES;

	// Player movement.
	int moveUp = 0;
	int moveDown = 0;
	int moveLeft = 0;
	int moveRight = 0;
	
	vec2 rawMoveAxis;
	vec2 moveAxis;
	
	bool jump = false;

	SDL_Scancode nullButton = SDL_NUM_SCANCODES;
	SDL_Scancode buttonDown = nullButton;
	// Ideally buttonDown needs to be a list of buttonsPressed to stop actions from being interrupted.
	// In this use case a single button variable is fine as we only need jump, right now.

};

