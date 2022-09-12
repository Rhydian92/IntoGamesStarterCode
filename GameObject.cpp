#include <iostream>
#include "GameObject.h"

// vec2 has a default constructor - so (0, 0) will be passed in as default when _position is decalred.
GameObject::GameObject(vec2 _position)
	: position(_position)
{
}

void GameObject::Move(vec2 _moveBy)
{
	position += _moveBy;
}