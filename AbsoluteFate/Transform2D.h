#pragma once
#include "Vector2D.h"

class Transform2D
{
	Vector2D position;
	Vector2D scale;
	float rotation;

	Transform2D() :position(0, 0), scale(1, 1), rotation(0.0f) {};
	Transform2D(Vector2D pPosition =0, Vector2D pScale =1, float pRotation =0) : position(pPosition), scale(pScale), rotation(pRotation) {};
};

