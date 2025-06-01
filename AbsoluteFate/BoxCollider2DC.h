#pragma once
#include "Components.h"
#include "Transform.h"
#include "Actor.h"

#include "Rectangle.h"

class BoxCollider2DC : public Components
{
private:
	Transform mColliderBox;
	Actor* mParentActor;

public :
    BoxCollider2DC(Actor* pParentActor);
    BoxCollider2DC() = delete;
    BoxCollider2DC(const BoxCollider2DC&) = delete;

	virtual void OnStart() 
	{ 
		mParentActor = mOwner;
		mColliderBox = mOwner->GetTransform();
	};

    Transform GetColliderBox() const { return mColliderBox; };

    //Check if this collider box hit another collider box
    bool OnCollide() const;

    //Check face of this collider box hit another collider box
    FaceHit CollideFace();

    virtual void Update();
    virtual void Draw(RendererSDL& pRenderer);
    virtual void OnEnd() {};
};