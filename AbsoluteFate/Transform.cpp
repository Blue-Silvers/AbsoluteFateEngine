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
}

void Transform::RotateYInDegrees(float pDegrees)
{
}

void Transform::RotateZInDegrees(float pDegrees)
{
}
