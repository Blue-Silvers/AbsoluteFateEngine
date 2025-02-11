#pragma once
#include "Components.h"
#include "Transform2D.h"
#include "Actor.h"
class Actor;

class BoxCollider2D : public Components
{
private:
	Transform2D mColliderBox;
	Actor* mParentActor;

public :
	BoxCollider2D();
	virtual void OnStart() 
	{ 
		mParentActor = mOwner;
		mColliderBox = mOwner->GetTransform2D();
	};
};

