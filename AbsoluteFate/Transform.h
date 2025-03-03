#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix4Row.h"
#include "Maths.h"

class Transform
{
private:
	Vector3 mPosition;
	Vector3 mScale;
	Vector3 mRotation;

	bool mNeedsUpdate;
	Matrix4Row mWorldTransform;

public:
	Transform() :mPosition(0, 0, 0), mScale(1, 1, 1), mRotation(0, 0, 0), mNeedsUpdate(true) {};
	Transform(Vector3 pPosition = Vector3::zero, Vector3 pScale = Vector3::one, Vector3 pRotation = Vector3::zero) : mPosition(pPosition),
																													mScale(pScale),
																													mRotation(pRotation),
																													mNeedsUpdate(true) {};

	Transform(Vector2 pPosition = 0, Vector2 pScale = 1, float pRotation = 0) : mPosition(pPosition.x, pPosition.y, 0),
																				mScale(pScale.x, pScale.y, 1),
																				mRotation(0, 0, pRotation),
																				mNeedsUpdate(true) {};

	void ComputeWorldTransform();

	//Directions
	Vector3 Right() const { return Vector3(Maths::Cos(mRotation.z), -Maths::Sin(mRotation.z), 0); }
	Vector3 Up() const { return Vector3(Maths::Sin(mRotation.z), -Maths::Cos(mRotation.z), 0); }

	//Getter
	Vector3 GetScale() const { return mScale; };
	Vector3 GetPosition() const { return mPosition; };
	Vector3 GetRotation() const { return mRotation; };
	Matrix4Row GetWorldTransform() const { return mWorldTransform; };

	Vector2 GetScale2D() const { return {mScale.x, mScale.y}; };
	Vector2 GetPosition2D() const { return { mPosition.x, mPosition.y }; };
	float GetRotation2D() const { return mRotation.z; };
};

