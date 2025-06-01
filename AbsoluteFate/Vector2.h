#pragma once
#include"cmath"
#include "string"

struct Vector2
{
public:
	//Vector value
	float x = 0;
	float y = 0;

	//Base Vector
	static const Vector2 Zero;
	static const Vector2 One;

	//Set vector
	Vector2():x(0), y(0) {};
	Vector2(float pX, float pY) : x(pX), y(pY) {};
	Vector2(float size) : x(size), y(size) {};

	//Vector calculs
	inline void operator+=(Vector2& right)
	{
		x += right.x;
		y += right.y;
	}
	inline void operator-=(Vector2& right) 
	{
		x -= right.x;
		y -= right.y;
	}
	inline void operator*=(float scalar)
	{
		x *= scalar;
		y *= scalar;
	}
	inline void operator/=(float scalar)
	{
		x /= scalar;
		y /= scalar;
	}


	//2 vectors calculs
	friend Vector2 operator+(Vector2& left, Vector2& right) 
	{
		return { left.x + right.x, left.y + right.y };
	}
	friend Vector2 operator-(Vector2& left, Vector2& right)
	{
		return { left.x - right.x, left.y - right.y };
	}
	friend Vector2 operator*(Vector2& right, float scalar)
	{
		return { scalar * right.x, scalar * right.y };
	}
	friend Vector2 operator/(Vector2& left, float scalar)
	{
		return { left.x / scalar, left.y / scalar };
	}


	inline float GetMagnitude() const 
	{
		return sqrt(x * x + y * y); //return vector magnitude
	}
	inline void Normalize() 
	{
		(*this) /= GetMagnitude(); //calcul normalize vector
	}
	inline Vector2 Normalized() 
	{
		return (*this) / GetMagnitude(); //return normalize vector
	}
	friend float Dot(Vector2& left, Vector2& right)
	{
		return left.x * right.x + left.y * right.y; //return dot of 2 vectors
	}

	//Convert value to string for print when use vector whith log class
	inline std::string ToStrings() 
	{
		return "( " + std::to_string(x) + " , " + std::to_string(y) + " )";
	}
	inline std::string MagnitudeToStrings()
	{
		return "( " + std::to_string(GetMagnitude()) + " )";
	}
};