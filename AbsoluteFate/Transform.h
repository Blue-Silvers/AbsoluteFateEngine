#pragma once
#include "Vector2.h"
#include "Quaternion.h"
#include "Matrix4Row.h"
#include "Maths.h"

class Transform
{
private:
	Vector3 mPosition;
	Vector3 mScale;
	Quaternion mRotation;

	bool mNeedsUpdate = true;
	Matrix4Row mWorldTransform;
	Vector3 mRotationDegrees = Vector3(0, 0, 0);

public:
	Transform() :mPosition(0, 0, 0), mScale(1, 1, 1), mRotation(0, 0, 0, 0), mNeedsUpdate(true) {};
	Transform(Vector3 pPosition = Vector3::zero, Vector3 pScale = Vector3::one, Quaternion pRotation = Quaternion::Identity) : mPosition(pPosition),
																													mScale(pScale),
																													mRotation(pRotation),
																													mNeedsUpdate(true) {};

	Transform(Vector2 pPosition = 0, Vector2 pScale = 1, float pRotation = 0) : mPosition(pPosition.x, pPosition.y, 0),
																				mScale(pScale.x, pScale.y, 1),
																				mRotation(0, 0, pRotation, 1),
																				mNeedsUpdate(true) {};

	void ComputeWorldTransform();

	//Directions
	Vector2 Right2D() const { return Vector2(Maths::Cos(mRotation.z), -Maths::Sin(mRotation.z)); }
	Vector2 Up2D() const { return Vector2(-Maths::Sin(mRotation.z), Maths::Cos(mRotation.z)); }

	Vector3 Right() const { return Vector3::Transform(Vector3::unitY, mRotation); }
	Vector3 Up() const { return Vector3::Transform(Vector3::unitZ, mRotation); }
	Vector3 Forward() const { return Vector3::Transform(Vector3::unitX, mRotation); }
	//Vector3 Right() const { return Vector3(-mRotation.AsMatrixRow().mat[0][0], -mRotation.AsMatrixRow().mat[1][0], -mRotation.AsMatrixRow().mat[2][0]); }
	//Vector3 Up() const { return Vector3(mRotation.AsMatrixRow().mat[0][2], mRotation.AsMatrixRow().mat[1][2], mRotation.AsMatrixRow().mat[2][2]); }
	//Vector3 Forward() const { return Vector3(mRotation.AsMatrixRow().mat[0][1], mRotation.AsMatrixRow().mat[1][1], mRotation.AsMatrixRow().mat[2][1]); }

	//Rotator
	void RotateXInDegrees(float pDegrees);
	void RotateYInDegrees(float pDegrees);
	void RotateZInDegrees(float pDegrees);
	void Rotate2dInDegrees(float pDegrees);
	void Rotate(float pRotation, Vector3 pAxis);

	//Getter
	Vector3 GetScale() const { return mScale; };
	Vector3 GetPosition() const { return mPosition; };
	Quaternion GetRotation() const { return mRotation; };
	Matrix4Row GetWorldTransform() const { return mWorldTransform; };
	Vector3 GetRotationInDegrees() const { return mRotationDegrees; };

	Vector2 GetScale2D() const { return {mScale.x, mScale.y}; };
	Vector2 GetPosition2D() const { return { mPosition.x, mPosition.y }; };
	float GetRotation2D() const { return mRotation.z; };
	float GetRotation2dInDegrees() const { return mRotationDegrees.z; };
};

