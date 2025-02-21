#pragma once
#include "Components.h"
#include "Transform2D.h"
#include "Actor.h"

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
		mParentActor = mOwner;
		mColliderBox = mOwner->GetTransform2D();
	};

    Transform2D GetColliderBox() const { return mColliderBox; };

    //Check if this collider box hit another collider box
    bool OnCollide() const
    {
        for (Actor* actor : mOwner->GetScene()->GetAllActor())
        {
            if (mParentActor != actor)
            {
                for (Components* component : actor->GetAllComponent())
                {
                    if (BoxCollider2DC* pBoxCollider2DC = dynamic_cast<BoxCollider2DC*>(component))
                    {
                        if (mColliderBox.GetPosition().y < pBoxCollider2DC->GetColliderBox().GetPosition().y + pBoxCollider2DC->GetColliderBox().GetScale().y && mColliderBox.GetPosition().y + mColliderBox.GetScale().y > pBoxCollider2DC->GetColliderBox().GetPosition().y
                            && mColliderBox.GetPosition().x < pBoxCollider2DC->GetColliderBox().GetPosition().x + pBoxCollider2DC->GetColliderBox().GetScale().x && mColliderBox.GetPosition().x + mColliderBox.GetScale().x > pBoxCollider2DC->GetColliderBox().GetPosition().x)
                        {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    };

    //Check face of this collider box hit another collider box
    FaceHit CollideFace() const
    {
        for (Actor* actor : mOwner->GetScene()->GetAllActor())
        {
            for (Components* component : actor->GetAllComponent())
            {
                if (BoxCollider2DC* pBoxCollider2DC = dynamic_cast<BoxCollider2DC*>(component))
                {
                    if (mColliderBox.GetPosition().y < pBoxCollider2DC->GetColliderBox().GetPosition().y + pBoxCollider2DC->GetColliderBox().GetScale().y && mColliderBox.GetPosition().y + mColliderBox.GetScale().y > pBoxCollider2DC->GetColliderBox().GetPosition().y
                        && mColliderBox.GetPosition().x < pBoxCollider2DC->GetColliderBox().GetPosition().x + pBoxCollider2DC->GetColliderBox().GetScale().x && mColliderBox.GetPosition().x + mColliderBox.GetScale().x > pBoxCollider2DC->GetColliderBox().GetPosition().x)
                    {
                        float upCollide = mColliderBox.GetPosition().y - pBoxCollider2DC->GetColliderBox().GetPosition().y + pBoxCollider2DC->GetColliderBox().GetScale().y; //verify distance between top of this rectangle and bottom of other rectangle
                        float downCollide = mColliderBox.GetPosition().y + mColliderBox.GetScale().y - pBoxCollider2DC->GetColliderBox().GetPosition().y; //verify distance between bottom this rectangle and top of other rectangle
                        float rightCollide = mColliderBox.GetPosition().x + mColliderBox.GetScale().x - pBoxCollider2DC->GetColliderBox().GetPosition().x; //verify distance between right side of this rectangle and left side of other rectangle
                        float leftCollide = mColliderBox.GetPosition().x - pBoxCollider2DC->GetColliderBox().GetPosition().x + pBoxCollider2DC->GetColliderBox().GetScale().x; //verify distance between left side of this rectangle and right side of other rectangle

                        if (upCollide >= downCollide && upCollide >= rightCollide && upCollide >= leftCollide)
                        {
                            return UP;
                        }
                        else if (downCollide >= upCollide && downCollide >= rightCollide && downCollide >= leftCollide)
                        {
                            return DOWN;
                        }
                        else if (rightCollide >= upCollide && rightCollide >= downCollide && rightCollide >= leftCollide)
                        {
                            return RIGHT;
                        }
                        else if (leftCollide >= upCollide && leftCollide >= rightCollide && downCollide >= rightCollide)
                        {
                            return LEFT;
                        }
                    }
                }
            }
        }

        return NONE;
    };

    virtual void Update() {};
    virtual void Draw(Renderer& pRenderer) //debug
    {
        //Transform2D destinationRect = Transform2D( //debug box
        //    Vector2D(static_cast<int>(GetTransform2D().GetPosition().x - animation->GetTexWidth() / 2.0f),
        //        static_cast<int>(GetTransform2D().GetPosition().y - animation->GetTexHeight() / 2.0f)),
        //    Vector2D(static_cast<int>(animation->GetTexWidth() * GetTransform2D().GetScale().x),
        //        static_cast<int>(animation->GetTexHeight() * GetTransform2D().GetScale().y)),
        //    GetTransform2D().GetRotation());
        ////Debug draw sqr//
        //Rectangle rBox = Rectangle(destinationRect.GetPosition(), destinationRect.GetScale(), destinationRect.GetRotation());
        //SDL_SetRenderDrawColor(pRenderer.GetSdlRenderer(), 255, 255, 255, 255);
        //SDL_Rect sdlRect = rBox.ToSdlRect();
        //SDL_RenderFillRect(pRenderer.GetSdlRenderer(), &sdlRect);

    };
    virtual void OnEnd() {};
};

