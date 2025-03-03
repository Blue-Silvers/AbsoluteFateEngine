#include "Transform.h"

void Transform::ComputeWorldTransform()
{
	if (!mNeedsUpdate) 
	{
		return;
	}
	mNeedsUpdate = false;
	mWorldTransform = Matrix4Row::CreateScale(mScale);
	mWorldTransform *= Matrix4Row::CreateRotationX(mRotation.x);
	mWorldTransform *= Matrix4Row::CreateRotationY(mRotation.y);
	mWorldTransform *= Matrix4Row::CreateRotationZ(mRotation.z);
	mWorldTransform *= Matrix4Row::CreateTranslation(mPosition);
	//mOwner->UpdateComponentsTransform();
}
