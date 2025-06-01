#include "BoxCollider2DC.h"
#include "RendererSDL.h"
#include "SpriteC.h"

BoxCollider2DC::BoxCollider2DC(Actor* pParentActor) : Components(pParentActor, 0), mColliderBox(0), mParentActor(pParentActor)
{

}

bool BoxCollider2DC::OnCollide() const
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
}

FaceHit BoxCollider2DC::CollideFace()
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
}

void BoxCollider2DC::Update()
{
    for (Components* component : mOwner->GetAllComponent())
    {
        if (SpriteC* sprite = dynamic_cast<SpriteC*>(component))
        {
            mColliderBox = Transform( //debug box
                Vector2((mOwner->GetTransform().GetPosition().x - sprite->GetTexWidth() / 2.0f),
                    (mOwner->GetTransform().GetPosition().y - sprite->GetTexHeight() / 2.0f)),
                Vector2((sprite->GetTexWidth() * mOwner->GetTransform().GetScale().x),
                    (sprite->GetTexHeight() * mOwner->GetTransform().GetScale().y)),
                mOwner->GetTransform().GetRotation2D());
        }
    }
}

void BoxCollider2DC::Draw(RendererSDL& pRenderer) //debug
{
    ////Debug draw sqr//
    Rectangle rBox = { {(float)mColliderBox.GetPosition().x,(float)mColliderBox.GetPosition().y},{(float)mColliderBox.GetScale().x,(float)mColliderBox.GetScale().y} };
    SDL_SetRenderDrawColor(pRenderer.GetSdlRenderer(), 255, 255, 255, 255);
    SDL_Rect sdlRect = rBox.ToSdlRect();
    SDL_RenderFillRect(pRenderer.GetSdlRenderer(), &sdlRect);

}