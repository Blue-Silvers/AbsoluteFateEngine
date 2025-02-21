#pragma once
#include"cmath"
#include "string"
struct Vector2D
{
public:

	//Vector value
	float x = 0;
	float y = 0;


	//Base Vector
	static const Vector2D Zero;
	static const Vector2D One;

	//Set vector
	Vector2D():x(0), y(0) {};
	Vector2D(float pX, float pY) : x(pX), y(pY) {};
	Vector2D(float size) : x(size), y(size) {};

	//Vector calculs
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
	inline void operator=(Vector2D& other)
	{
		x = other.x;
		y = other.y;
	};
	//inline void operator=(const Vector2D& other) const
	//{
	//	x = other.x;
	//	y = other.y;
	//};

	//2 vectors calculs
	friend Vector2D operator+(Vector2D& left, Vector2D& right) 
	{
		return { left.x + right.x, left.y + right.y };
	}
	friend Vector2D operator-(Vector2D& left, Vector2D& right)
	{
		return { left.x - right.x, left.y - right.y };
	}
	friend Vector2D operator*(Vector2D& right, float scalar)
	{
		return { scalar * right.x, scalar * right.y };
	}
	friend Vector2D operator/(Vector2D& left, float scalar)
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
	inline Vector2D Normalized() 
	{
		return (*this) / GetMagnitude(); //return normalize vector
	}
	friend float Dot(Vector2D& left, Vector2D& right)
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


