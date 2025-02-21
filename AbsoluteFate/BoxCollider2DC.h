#pragma once
#include "Components.h"
#include "Transform2D.h"
#include "Actor.h"
#include "AnimatedSpriteC.h"

class BoxCollider2DC : public Components
{
private:
	Transform2D mColliderBox;
	Actor* mParentActor;

public :
    BoxCollider2DC(Transform2D pColliderBox, Actor* pParentActor);
    BoxCollider2DC() = delete;
    BoxCollider2DC(const BoxCollider2DC&) = delete;

	virtual void OnStart() 
	{ 
	};

    Transform2D GetColliderBox() const { return mColliderBox; };

    //Check if this collider box hit another collider box
    bool OnCollide() const;

    //Check face of this collider box hit another collider box
    FaceHit CollideFace() const;

    virtual void Update() {};
    virtual void Draw(Renderer& pRenderer) //debug
    {
                                //Debug draw sqr//
        OnCollide();
        Rectangle rBox = { {(float)mColliderBox.GetPosition().x,(float)mColliderBox.GetPosition().y},{(float)mColliderBox.GetScale().x,(float)mColliderBox.GetScale().y} };
        SDL_SetRenderDrawColor(pRenderer.GetSdlRenderer(), 255, 255, 255, 255);
        SDL_Rect sdlRect = rBox.ToSdlRect();
        SDL_RenderFillRect(pRenderer.GetSdlRenderer(), &sdlRect);
                                //////////////////
    };
    virtual void OnEnd() {};

    virtual void SetPosition(Vector2D pNewPosition) //set position
    {
        mColliderBox = Transform2D(pNewPosition, mColliderBox.GetScale(), mColliderBox.GetRotation());
    };
    virtual void SetScale(Vector2D pNewScale) //set scale
    {
        mColliderBox = Transform2D(mColliderBox.GetPosition(), pNewScale, mColliderBox.GetRotation());
    };
};

