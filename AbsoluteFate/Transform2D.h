#pragma once
#include "Vector2D.h"
#include "Maths.h"

class Transform2D
{
private:
	Vector2D position;
	Vector2D scale;
	float rotation;

public:
	Transform2D() :position(0, 0), scale(1, 1), rotation(0.0f) {};
	Transform2D(Vector2D pPosition =0, Vector2D pScale =1, float pRotation =0) : position(pPosition), scale(pScale), rotation(pRotation) {};
	
	//Operator
	//static const Transform2D NullRect;
	/*inline void operator=(Transform2D& other)
	{
		position = other.position;
		scale = other.scale;
	};
	inline void operator=(const Transform2D& other) const
	{
		position = other.position;
		scale = other.scale;
	};*/
	bool operator==(const Transform2D& other) const
	{
		return position.x == other.position.x &&
			position.y == other.position.y &&
			scale.x == other.scale.x &&
			scale.y == other.scale.y;
	};
	bool operator!=(const Transform2D& other) const {
		return !(*this == other);
	};

	//Directions
	Vector2D Right() const { return Vector2D(Maths::Cos(rotation), -Maths::Sin(rotation)); }
	Vector2D Up() const { return Vector2D(Maths::Sin(rotation), -Maths::Cos(rotation)); }

	//Getter
	Vector2D GetScale() const { return scale; };
	Vector2D GetPosition() const { return position; };
	float GetRotation() const { return rotation; };

	/*Vector2D SetPos(Vector2D newPosition) { scale = newPosition; };
	Vector2D SetScale(Vector2D newScale) { scale = newScale; };
	float SetRotation(float newRot) { rotation = newRot; };*/
};

