#pragma once
#include "Components.h"
#include "Transform2D.h"
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
	};
};

