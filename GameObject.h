#pragma once
#include "vec2.h"


class GameObject
{
public:
	GameObject(vec2);

	//void SetXPosition(int _x);
	//int GetXPosition();

	//void SetYPosition(int _y);
	//int GetYPosition();

	void Move(vec2);

	vec2 position;
private:


protected:
};