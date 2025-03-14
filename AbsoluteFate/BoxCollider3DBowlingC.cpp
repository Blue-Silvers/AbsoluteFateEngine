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
                    if (mParentActor->GetTransform().GetWorldTransform().GetTranslation().y < actor->GetTransform().GetWorldTransform().GetTranslation().y + actor->GetTransform().GetWorldTransform().GetScale().y * boxCollider3DC->GetCustomSize().y && mParentActor->GetTransform().GetWorldTransform().GetTranslation().y + mParentActor->GetTransform().GetWorldTransform().GetScale().y * mCustomScale.y > actor->GetTransform().GetWorldTransform().GetTranslation().y
                        && mParentActor->GetTransform().GetWorldTransform().GetTranslation().x < actor->GetTransform().GetWorldTransform().GetTranslation().x + actor->GetTransform().GetWorldTransform().GetScale().x * boxCollider3DC->GetCustomSize().x && mParentActor->GetTransform().GetWorldTransform().GetTranslation().x + mParentActor->GetTransform().GetWorldTransform().GetScale().x * mCustomScale.x > actor->GetTransform().GetWorldTransform().GetTranslation().x
                        && mParentActor->GetTransform().GetWorldTransform().GetTranslation().z < actor->GetTransform().GetWorldTransform().GetTranslation().z + actor->GetTransform().GetWorldTransform().GetScale().z * boxCollider3DC->GetCustomSize().z && mParentActor->GetTransform().GetWorldTransform().GetTranslation().z + mParentActor->GetTransform().GetWorldTransform().GetScale().z * mCustomScale.z > actor->GetTransform().GetWorldTransform().GetTranslation().z)
                    {
                        return true;
                    }
                }
            }

        }
        if (SetOfPinA* setOfPinA = dynamic_cast<SetOfPinA*>(actor))
        {
            for (PinA* pinA : setOfPinA->GetPinList())
            {
                if (mParentActor != actor)
                {
                    //pinA->GetTransform().GetWorldTransform().GetTranslation()
                    if (mParentActor->GetTransform().GetWorldTransform().GetTranslation().y < pinA->GetTransform().GetWorldTransform().GetTranslation().y + pinA->GetTransform().GetWorldTransform().GetScale().y * pinA->GetBoxCollider()->GetCustomSize().y && mParentActor->GetTransform().GetWorldTransform().GetTranslation().y + mParentActor->GetTransform().GetWorldTransform().GetScale().y * mCustomScale.y > pinA->GetTransform().GetWorldTransform().GetTranslation().y
                        && mParentActor->GetTransform().GetWorldTransform().GetTranslation().x < pinA->GetTransform().GetWorldTransform().GetTranslation().x + pinA->GetTransform().GetWorldTransform().GetScale().x * pinA->GetBoxCollider()->GetCustomSize().x && mParentActor->GetTransform().GetWorldTransform().GetTranslation().x + mParentActor->GetTransform().GetWorldTransform().GetScale().x * mCustomScale.x > pinA->GetTransform().GetWorldTransform().GetTranslation().x
                        && mParentActor->GetTransform().GetWorldTransform().GetTranslation().z < pinA->GetTransform().GetWorldTransform().GetTranslation().z + pinA->GetTransform().GetWorldTransform().GetScale().z * pinA->GetBoxCollider()->GetCustomSize().z && mParentActor->GetTransform().GetWorldTransform().GetTranslation().z + mParentActor->GetTransform().GetWorldTransform().GetScale().z * mCustomScale.z > pinA->GetTransform().GetWorldTransform().GetTranslation().z)
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
                    if (mParentActor->GetTransform().GetWorldTransform().GetTranslation().y < actor->GetTransform().GetWorldTransform().GetTranslation().y + actor->GetTransform().GetWorldTransform().GetScale().y * boxCollider3DC->GetCustomSize().y && mParentActor->GetTransform().GetWorldTransform().GetTranslation().y + mParentActor->GetTransform().GetWorldTransform().GetScale().y * mCustomScale.y > actor->GetTransform().GetWorldTransform().GetTranslation().y
                        && mParentActor->GetTransform().GetWorldTransform().GetTranslation().x < actor->GetTransform().GetWorldTransform().GetTranslation().x + actor->GetTransform().GetWorldTransform().GetScale().x * boxCollider3DC->GetCustomSize().x && mParentActor->GetTransform().GetWorldTransform().GetTranslation().x + mParentActor->GetTransform().GetWorldTransform().GetScale().x * mCustomScale.x > actor->GetTransform().GetWorldTransform().GetTranslation().x
                        && mParentActor->GetTransform().GetWorldTransform().GetTranslation().z < actor->GetTransform().GetWorldTransform().GetTranslation().z + actor->GetTransform().GetWorldTransform().GetScale().z * boxCollider3DC->GetCustomSize().z && mParentActor->GetTransform().GetWorldTransform().GetTranslation().z + mParentActor->GetTransform().GetWorldTransform().GetScale().z * mCustomScale.z > actor->GetTransform().GetWorldTransform().GetTranslation().z) 
                    {

                        return mParentActor->GetTransform().GetWorldTransform().GetTranslation() - actor->GetTransform().GetWorldTransform().GetTranslation();
                    }
                }
            }

        }
        if (SetOfPinA* setOfPinA = dynamic_cast<SetOfPinA*>(actor))
            {
                for (PinA* pinA : setOfPinA->GetPinList())
                {
                    if (mParentActor != actor)
                    {
                        if (mParentActor->GetTransform().GetWorldTransform().GetTranslation().y < pinA->GetTransform().GetWorldTransform().GetTranslation().y + pinA->GetTransform().GetWorldTransform().GetScale().y * pinA->GetBoxCollider()->GetCustomSize().y && mParentActor->GetTransform().GetWorldTransform().GetTranslation().y + mParentActor->GetTransform().GetWorldTransform().GetScale().y * mCustomScale.y > pinA->GetTransform().GetWorldTransform().GetTranslation().y
                            && mParentActor->GetTransform().GetWorldTransform().GetTranslation().x < pinA->GetTransform().GetWorldTransform().GetTranslation().x + pinA->GetTransform().GetWorldTransform().GetScale().x * pinA->GetBoxCollider()->GetCustomSize().x && mParentActor->GetTransform().GetWorldTransform().GetTranslation().x + mParentActor->GetTransform().GetWorldTransform().GetScale().x * mCustomScale.x > pinA->GetTransform().GetWorldTransform().GetTranslation().x
                            && mParentActor->GetTransform().GetWorldTransform().GetTranslation().z < pinA->GetTransform().GetWorldTransform().GetTranslation().z + pinA->GetTransform().GetWorldTransform().GetScale().z * pinA->GetBoxCollider()->GetCustomSize().z && mParentActor->GetTransform().GetWorldTransform().GetTranslation().z + mParentActor->GetTransform().GetWorldTransform().GetScale().z * mCustomScale.z > pinA->GetTransform().GetWorldTransform().GetTranslation().z)
                        {
                            return mParentActor->GetTransform().GetWorldTransform().GetTranslation() - pinA->GetTransform().GetWorldTransform().GetTranslation();
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
                    if (mParentActor->GetTransform().GetWorldTransform().GetTranslation().y < actor->GetTransform().GetWorldTransform().GetTranslation().y + actor->GetTransform().GetWorldTransform().GetScale().y * boxCollider3DC->GetCustomSize().y && mParentActor->GetTransform().GetWorldTransform().GetTranslation().y + mParentActor->GetTransform().GetWorldTransform().GetScale().y * mCustomScale.y > actor->GetTransform().GetWorldTransform().GetTranslation().y
                        && mParentActor->GetTransform().GetWorldTransform().GetTranslation().x < actor->GetTransform().GetWorldTransform().GetTranslation().x + actor->GetTransform().GetWorldTransform().GetScale().x * boxCollider3DC->GetCustomSize().x && mParentActor->GetTransform().GetWorldTransform().GetTranslation().x + mParentActor->GetTransform().GetWorldTransform().GetScale().x * mCustomScale.x > actor->GetTransform().GetWorldTransform().GetTranslation().x
                        && mParentActor->GetTransform().GetWorldTransform().GetTranslation().z < actor->GetTransform().GetWorldTransform().GetTranslation().z + actor->GetTransform().GetWorldTransform().GetScale().z * boxCollider3DC->GetCustomSize().z && mParentActor->GetTransform().GetWorldTransform().GetTranslation().z + mParentActor->GetTransform().GetWorldTransform().GetScale().z * mCustomScale.z > actor->GetTransform().GetWorldTransform().GetTranslation().z)
                    {

                        return actor;
                    }
                }
            }

        }
        if (SetOfPinA* setOfPinA = dynamic_cast<SetOfPinA*>(actor))
        {
            for (PinA* pinA : setOfPinA->GetPinList())
            {
                if (mParentActor != actor)
                {
                    if (mParentActor->GetTransform().GetWorldTransform().GetTranslation().y < pinA->GetTransform().GetWorldTransform().GetTranslation().y + pinA->GetTransform().GetWorldTransform().GetScale().y * pinA->GetBoxCollider()->GetCustomSize().y && mParentActor->GetTransform().GetWorldTransform().GetTranslation().y + mParentActor->GetTransform().GetWorldTransform().GetScale().y * mCustomScale.y > pinA->GetTransform().GetWorldTransform().GetTranslation().y
                        && mParentActor->GetTransform().GetWorldTransform().GetTranslation().x < pinA->GetTransform().GetWorldTransform().GetTranslation().x + pinA->GetTransform().GetWorldTransform().GetScale().x * pinA->GetBoxCollider()->GetCustomSize().x && mParentActor->GetTransform().GetWorldTransform().GetTranslation().x + mParentActor->GetTransform().GetWorldTransform().GetScale().x * mCustomScale.x > pinA->GetTransform().GetWorldTransform().GetTranslation().x
                        && mParentActor->GetTransform().GetWorldTransform().GetTranslation().z < pinA->GetTransform().GetWorldTransform().GetTranslation().z + pinA->GetTransform().GetWorldTransform().GetScale().z * pinA->GetBoxCollider()->GetCustomSize().z && mParentActor->GetTransform().GetWorldTransform().GetTranslation().z + mParentActor->GetTransform().GetWorldTransform().GetScale().z * mCustomScale.z > pinA->GetTransform().GetWorldTransform().GetTranslation().z)
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

