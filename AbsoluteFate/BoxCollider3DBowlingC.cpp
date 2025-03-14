#include "BoxCollider3DBowlingC.h"
#include "SetOfPinA.h"

#include "Log.h"

BoxCollider3DBowlingC::BoxCollider3DBowlingC(Actor* pParentActor) : Components(pParentActor, 0), mParentActor(pParentActor), mCustomScale(pParentActor->GetTransform().GetScale())
{

}

bool BoxCollider3DBowlingC::OnCollide() const
{
    for (Actor* actor : mOwner->GetScene()->GetAllActor())
    {
        if (mParentActor != actor)
        {
            for (Components* component : actor->GetAllComponent())
            {
                if (BoxCollider3DBowlingC* boxCollider3DC = dynamic_cast<BoxCollider3DBowlingC*>(component))
                {
                    if (mParentActor->GetTransform().GetPosition().y < actor->GetTransform().GetPosition().y + actor->GetTransform().GetScale().y * boxCollider3DC->GetCustomSize().y && mParentActor->GetTransform().GetPosition().y + mParentActor->GetTransform().GetScale().y * mCustomScale.y > actor->GetTransform().GetPosition().y
                        && mParentActor->GetTransform().GetPosition().x < actor->GetTransform().GetPosition().x + actor->GetTransform().GetScale().x * boxCollider3DC->GetCustomSize().x && mParentActor->GetTransform().GetPosition().x + mParentActor->GetTransform().GetScale().x * mCustomScale.x > actor->GetTransform().GetPosition().x
                        && mParentActor->GetTransform().GetPosition().z < actor->GetTransform().GetPosition().z + actor->GetTransform().GetScale().z * boxCollider3DC->GetCustomSize().z && mParentActor->GetTransform().GetPosition().z + mParentActor->GetTransform().GetScale().z * mCustomScale.z > actor->GetTransform().GetPosition().z)
                    {
                        return true;
                    }
                }
            }
            if (SetOfPinA* setOfPinA = dynamic_cast<SetOfPinA*>(actor))
            {
                for (PinA* pinA : setOfPinA->GetPinList())
                {
                    
                    if (mParentActor->GetTransform().GetPosition().y < pinA->GetTransform().GetPosition().y + pinA->GetTransform().GetScale().y * pinA->GetBoxCollider()->GetCustomSize().y && mParentActor->GetTransform().GetPosition().y + mParentActor->GetTransform().GetScale().y * mCustomScale.y > pinA->GetTransform().GetPosition().y
                        && mParentActor->GetTransform().GetPosition().x < pinA->GetTransform().GetPosition().x + pinA->GetTransform().GetScale().x * pinA->GetBoxCollider()->GetCustomSize().x && mParentActor->GetTransform().GetPosition().x + mParentActor->GetTransform().GetScale().x * mCustomScale.x > pinA->GetTransform().GetPosition().x
                        && mParentActor->GetTransform().GetPosition().z < pinA->GetTransform().GetPosition().z + pinA->GetTransform().GetScale().z * pinA->GetBoxCollider()->GetCustomSize().z && mParentActor->GetTransform().GetPosition().z + mParentActor->GetTransform().GetScale().z * mCustomScale.z > pinA->GetTransform().GetPosition().z)
                    {
                        return true;
                    }
                }
            }
        }

    }

    return false;
}

Vector3 BoxCollider3DBowlingC::GetDistance()
{
    for (Actor* actor : mOwner->GetScene()->GetAllActor())
    {
        if (mParentActor != actor)
        {
            for (Components* component : actor->GetAllComponent())
            {
                if (BoxCollider3DBowlingC* boxCollider3DC = dynamic_cast<BoxCollider3DBowlingC*>(component))
                {
                    if (mParentActor->GetTransform().GetPosition().y < actor->GetTransform().GetPosition().y + actor->GetTransform().GetScale().y * boxCollider3DC->GetCustomSize().y && mParentActor->GetTransform().GetPosition().y + mParentActor->GetTransform().GetScale().y * mCustomScale.y > actor->GetTransform().GetPosition().y
                        && mParentActor->GetTransform().GetPosition().x < actor->GetTransform().GetPosition().x + actor->GetTransform().GetScale().x * boxCollider3DC->GetCustomSize().x && mParentActor->GetTransform().GetPosition().x + mParentActor->GetTransform().GetScale().x * mCustomScale.x > actor->GetTransform().GetPosition().x
                        && mParentActor->GetTransform().GetPosition().z < actor->GetTransform().GetPosition().z + actor->GetTransform().GetScale().z * boxCollider3DC->GetCustomSize().z && mParentActor->GetTransform().GetPosition().z + mParentActor->GetTransform().GetScale().z * mCustomScale.z > actor->GetTransform().GetPosition().z)
                    {

                        return mParentActor->GetTransform().GetPosition() - actor->GetTransform().GetPosition();
                    }
                }
            }
            if (SetOfPinA* setOfPinA = dynamic_cast<SetOfPinA*>(actor))
            {
                for (PinA* pinA : setOfPinA->GetPinList())
                {
                    if (mParentActor->GetTransform().GetPosition().y < pinA->GetTransform().GetPosition().y + pinA->GetTransform().GetScale().y * pinA->GetBoxCollider()->GetCustomSize().y && mParentActor->GetTransform().GetPosition().y + mParentActor->GetTransform().GetScale().y * mCustomScale.y > pinA->GetTransform().GetPosition().y
                        && mParentActor->GetTransform().GetPosition().x < pinA->GetTransform().GetPosition().x + pinA->GetTransform().GetScale().x * pinA->GetBoxCollider()->GetCustomSize().x && mParentActor->GetTransform().GetPosition().x + mParentActor->GetTransform().GetScale().x * mCustomScale.x > pinA->GetTransform().GetPosition().x
                        && mParentActor->GetTransform().GetPosition().z < pinA->GetTransform().GetPosition().z + pinA->GetTransform().GetScale().z * pinA->GetBoxCollider()->GetCustomSize().z && mParentActor->GetTransform().GetPosition().z + mParentActor->GetTransform().GetScale().z * mCustomScale.z > pinA->GetTransform().GetPosition().z)
                    {
                        return mParentActor->GetTransform().GetPosition() - pinA->GetTransform().GetPosition();
                    }
                }
            }
        }
    }
}

Actor* BoxCollider3DBowlingC::GetCollideActor()
{
    for (Actor* actor : mOwner->GetScene()->GetAllActor())
    {
        if (mParentActor != actor)
        {
            for (Components* component : actor->GetAllComponent())
            {
                if (BoxCollider3DBowlingC* boxCollider3DC = dynamic_cast<BoxCollider3DBowlingC*>(component))
                {
                    if (mParentActor->GetTransform().GetPosition().y < actor->GetTransform().GetPosition().y + actor->GetTransform().GetScale().y * boxCollider3DC->GetCustomSize().y && mParentActor->GetTransform().GetPosition().y + mParentActor->GetTransform().GetScale().y * mCustomScale.y > actor->GetTransform().GetPosition().y
                        && mParentActor->GetTransform().GetPosition().x < actor->GetTransform().GetPosition().x + actor->GetTransform().GetScale().x * boxCollider3DC->GetCustomSize().x && mParentActor->GetTransform().GetPosition().x + mParentActor->GetTransform().GetScale().x * mCustomScale.x > actor->GetTransform().GetPosition().x
                        && mParentActor->GetTransform().GetPosition().z < actor->GetTransform().GetPosition().z + actor->GetTransform().GetScale().z * boxCollider3DC->GetCustomSize().z && mParentActor->GetTransform().GetPosition().z + mParentActor->GetTransform().GetScale().z * mCustomScale.z > actor->GetTransform().GetPosition().z)
                    {

                        return actor;
                    }
                }
            }
            if (SetOfPinA* setOfPinA = dynamic_cast<SetOfPinA*>(actor))
            {
                for (PinA* pinA : setOfPinA->GetPinList())
                {
                    if (mParentActor->GetTransform().GetPosition().y < pinA->GetTransform().GetPosition().y + pinA->GetTransform().GetScale().y * pinA->GetBoxCollider()->GetCustomSize().y && mParentActor->GetTransform().GetPosition().y + mParentActor->GetTransform().GetScale().y * mCustomScale.y > pinA->GetTransform().GetPosition().y
                        && mParentActor->GetTransform().GetPosition().x < pinA->GetTransform().GetPosition().x + pinA->GetTransform().GetScale().x * pinA->GetBoxCollider()->GetCustomSize().x && mParentActor->GetTransform().GetPosition().x + mParentActor->GetTransform().GetScale().x * mCustomScale.x > pinA->GetTransform().GetPosition().x
                        && mParentActor->GetTransform().GetPosition().z < pinA->GetTransform().GetPosition().z + pinA->GetTransform().GetScale().z * pinA->GetBoxCollider()->GetCustomSize().z && mParentActor->GetTransform().GetPosition().z + mParentActor->GetTransform().GetScale().z * mCustomScale.z > pinA->GetTransform().GetPosition().z)
                    {
                        return pinA;
                    }
                }
            }
        }
    }
}

void BoxCollider3DBowlingC::Update()
{
}

void BoxCollider3DBowlingC::Draw(RendererSDL& pRenderer)
{
}

