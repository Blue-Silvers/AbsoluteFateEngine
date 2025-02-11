#pragma once
#include "Vector2D.h"

class Transform2D
{
private:
	Vector2D position;
	Vector2D scale;
	float rotation;

public:
	Transform2D() :position(0, 0), scale(1, 1), rotation(0.0f) {};
	Transform2D(Vector2D pPosition =0, Vector2D pScale =1, float pRotation =0) : position(pPosition), scale(pScale), rotation(pRotation) {};
	
	//Directions
	Vector2D Right() const { return Vector2D(Maths::Cos(rotation), -Maths::Sin(rotation)); }
	Vector2D Up() const { return Vector2D(Maths::Sin(rotation), -Maths::Cos(rotation)); }

	//Getter
	Vector2D GetScale() { return scale; };
	Vector2D GetPosition() { return position; };
	float GetRotation() { return rotation; };
};

