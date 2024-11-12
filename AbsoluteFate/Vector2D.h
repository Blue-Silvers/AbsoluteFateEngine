#pragma once
#include"cmath"
#include "string"
struct Vector2D
{
public:
	float x = 0;
	float y = 0;

	static const Vector2D Zero;
	static const Vector2D One;

	Vector2D():x(0), y(0) {};
	Vector2D(float pX, float pY) : x(pX), y(pY) {};

	inline void operator+=(Vector2D& right)
	{
		x += right.x;
		y += right.y;
	}
	inline void operator-=(Vector2D& right) 
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

	friend Vector2D operator+(Vector2D& left, Vector2D& right) 
	{
		return { left.x + right.x, left.y + right.y };
	}
	friend Vector2D operator-(Vector2D& left, Vector2D& right)
	{
		return { left.x - right.x, left.y - right.y };
	}
	friend Vector2D operator*(float scalar, Vector2D& right)
	{
		return { scalar * right.x, scalar * right.y };
	}
	friend Vector2D operator/(Vector2D& left, float scalar)
	{
		return { left.x / scalar, left.y / scalar };
	}


	inline float GetMagnitude() const 
	{
		return sqrt(x * x + y * y);
	}
	inline void Normalize() 
	{
		(*this) /= GetMagnitude();
	}
	inline Vector2D Normalized() 
	{
		return (*this) / GetMagnitude();
	}
	friend float Dot(Vector2D& left, Vector2D& right)
	{
		return left.x * right.x + left.y * right.y;
	}

	inline std::string ToStrings() 
	{
		return "( " + std::to_string(x) + " , " + std::to_string(y) + " )";
	}
	inline std::string MagnitudeToStrings()
	{
		return "( " + std::to_string(GetMagnitude()) + " )";
	}
};


