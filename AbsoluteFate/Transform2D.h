#pragma once
#include "Vector2.h"
#include "Maths.h"

class Transform2D
{
private:
	Vector2 position;
	Vector2 scale;
	float rotation;

public:
	Transform2D() :position(0, 0), scale(1, 1), rotation(0.0f) {};
	Transform2D(Vector2 pPosition =0, Vector2 pScale =1, float pRotation =0) : position(pPosition), scale(pScale), rotation(pRotation) {};
	

	//Directions
	Vector2 Right() const { return Vector2(Maths::Cos(rotation), -Maths::Sin(rotation)); }
	Vector2 Up() const { return Vector2(Maths::Sin(rotation), -Maths::Cos(rotation)); }

	//Getter
	Vector2 GetScale() const { return scale; };
	Vector2 GetPosition() const { return position; };
	float GetRotation() const { return rotation; };
};

