#include "Transform.h"

void Transform::ComputeWorldTransform()
{
	if (!mNeedsUpdate) 
	{
		return;
	}
	mNeedsUpdate = false;
	mWorldTransform = Matrix4Row::CreateScale(mScale);
	mWorldTransform *= Matrix4Row::CreateFromQuaternion(mRotation);
	mWorldTransform *= Matrix4Row::CreateTranslation(mPosition);
	//mOwner->UpdateComponentsTransform();
}

void Transform::RotateXInDegrees(float pDegrees)
{
	mRotationDegrees.x = pDegrees;
	mRotation = mRotation.Concatenate(mRotation, Quaternion(Vector3{ 1,0,0 }, Maths::ToRad(pDegrees))); // X
	mNeedsUpdate = true;
	ComputeWorldTransform();
}

void Transform::RotateYInDegrees(float pDegrees)
{
	mRotationDegrees.y = pDegrees;
	mRotation = mRotation.Concatenate(mRotation, Quaternion(Vector3{ 0,1,0 }, Maths::ToRad(pDegrees))); // Y
	mNeedsUpdate = true;
	ComputeWorldTransform();
}

void Transform::RotateZInDegrees(float pDegrees)
{
	mRotationDegrees.z = pDegrees;
	mRotation = mRotation.Concatenate(mRotation, Quaternion(Vector3{ 0,0,1 }, Maths::ToRad(pDegrees))); // Z
	mNeedsUpdate = true;
	ComputeWorldTransform();
}

void Transform::Rotate2dInDegrees(float pDegrees)
{
	mRotationDegrees.z = pDegrees;
	mRotation = mRotation.Concatenate(mRotation, Quaternion(Vector3{ 0,0,1 }, Maths::ToRad(pDegrees))); // Z (2D axis)
	mNeedsUpdate = true;
	ComputeWorldTransform();
}

void Transform::Rotate(float pRotation, Vector3 pAxis)
{
	Quaternion increment(pAxis, pRotation);
	mRotation = Quaternion::Concatenate(mRotation, increment);
	mNeedsUpdate = true;
	ComputeWorldTransform();
}
