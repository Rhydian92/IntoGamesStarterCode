#include "vec2.h"

vec2::vec2()
	: x(0), y(0)
{
}

vec2::vec2(float _x, float _y)
	: x(_x), y(_y)
{
}

vec2::vec2(const vec2& other)
	: x(other.x), y(other.y)
{
}

void vec2::SetX(float _x)
{
	x = _x;
}

void vec2::SetY(float _y)
{
	y = _y;
}

// Addition
vec2 vec2::operator+(const vec2& other)
{
	vec2 result = vec2(x + other.x, y + other.y);
	return result;
}
vec2& vec2::operator+=(const vec2& other)
{
	*this = *this + other;
	return *this;
}

// Subtraction
vec2 vec2::operator-(const vec2& other)
{
	vec2 result = vec2(x - other.x, y - other.y);
	return result;
}
vec2& vec2::operator-=(const vec2& other)
{
	*this = *this - other;
	return *this;
}

// Multiplication.
vec2 vec2::operator*(float other)
{
	return vec2(x*other, y*other);
}
vec2& vec2::operator*=(float other)
{
	*this = *this * other;
	return *this;
}

vec2 vec2::operator/(float other)
{
	return vec2(x / other, y / other);
}
vec2& vec2::operator/=(float other)
{
	*this = *this / other;
	return *this;
}

// Getters
float vec2::GetX() const
{
	return x;
}
float vec2::GetY() const
{
	return y;
}

vec2 vec2::Up()
{
	return vec2(0, -1);
}
vec2 vec2::Down()
{
	return vec2(0, 1);
}
vec2 vec2::Left()
{
	return vec2(-1, 0);
}
vec2 vec2::Right()
{
	return vec2(1, 0);
}

vec2 vec2::Zero()
{
	return vec2(0, 0);
}

// This needs some checking... Do we use *this??
// != should call this method and return the oposite.
bool vec2::operator==(const vec2& other)
{
	if ((this->x = other.x) && (this->y = other.y))
		return true;
	else
		return false;
}

//VECTOR MATHS
vec2 vec2::Normalized()
{
	float magnitude = Magnitude();
	if (magnitude == 0)
	{
		return vec2(0, 0);
	}
	else
	{
		float k = 1 / magnitude;
		return vec2(k * x, k * y);
	}
}

float vec2::Magnitude()
{
	return sqrt(RelativeMagnitude());
}

// Optimisation 
float vec2::RelativeMagnitude()
{
	return (x * x) + (y * y);
}



std::ostream& operator<<(std::ostream& os, const vec2& pofloat) {
	os << "(" << pofloat.x << ", " << pofloat.y << ")\n";
	return os;
}