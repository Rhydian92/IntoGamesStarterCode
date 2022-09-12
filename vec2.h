#pragma once
#include <iostream>

class vec2
{
public:
	vec2();
	vec2(float _x, float _y);
	vec2(const vec2& other);

	void SetX(float _x);
	void SetY(float _y);
	float GetX() const;
	float GetY() const;

	static vec2 Up() ;
	static vec2 Down();
	static vec2 Left();
	static vec2 Right();
	static vec2 Zero();
	
	bool operator==(const vec2& other);
	bool operator!=(const vec2& other);

	// Addition of vec2s.
	vec2 operator+(const vec2& other);
	vec2& operator+=(const vec2& other);
	
	// Subtraction of vec2s.
	vec2 operator-(const vec2& other);
	vec2& operator-=(const vec2& other);

	// Multiplication by float.
	vec2 operator*(float other);
	vec2& operator*=(float other);

	// Division by float.
	vec2 operator/(float other);
	vec2& operator/=(float other);

	//VECTOR MATHS
	vec2 Normalized();
	float Magnitude();
	float RelativeMagnitude();


	friend std::ostream& operator<<(std::ostream& os, const vec2& pofloat);

private:
	float x, y;
};

