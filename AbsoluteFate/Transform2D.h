#pragma once
#include "Vector2D.h"

class Transform2D
{
	Vector2D position;
	Vector2D scale;
	float rotation;

	Transform2D() :position(0, 0), scale(1, 1), rotation(0.0f) {};
	Transform2D(Vector2D pPosition, Vector2D pScale, float pRotation) : position(pPosition), scale(pScale), rotation(pRotation) {};
};

