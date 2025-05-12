#include "DoomBoxCollider3DC.h"
#include "DoomLevel.h"

DoomBoxCollider3DC::DoomBoxCollider3DC(Actor* pParentActor) : Components(pParentActor, 0), mParentActor(pParentActor), mCustomScale(pParentActor->GetTransform().GetScale())
{

}

bool DoomBoxCollider3DC::OnCollide() const
{
    for (Actor* actor : mOwner->GetScene()->GetAllActor())
    {
        if (DoomLevel* doomLevel = dynamic_cast<DoomLevel*>(actor))
        {
            for (Actor* wall : doomLevel->GetLevelElements())
            {
                for (Components* component : wall->GetAllComponent())
                {
                    if (DoomBoxCollider3DC* boxCollider3DC = dynamic_cast<DoomBoxCollider3DC*>(component))
                    {
                        if (mParentActor->GetTransform().GetWorldTransform().GetTranslation().y < wall->GetTransform().GetWorldTransform().GetTranslation().y + wall->GetTransform().GetWorldTransform().GetScale().y * boxCollider3DC->GetBoxCollider()->GetCustomSize().y && mParentActor->GetTransform().GetWorldTransform().GetTranslation().y + mParentActor->GetTransform().GetWorldTransform().GetScale().y * mCustomScale.y > wall->GetTransform().GetWorldTransform().GetTranslation().y - wall->GetTransform().GetWorldTransform().GetScale().y * boxCollider3DC->GetBoxCollider()->GetCustomSize().y
                            && mParentActor->GetTransform().GetWorldTransform().GetTranslation().x < wall->GetTransform().GetWorldTransform().GetTranslation().x + wall->GetTransform().GetWorldTransform().GetScale().x * boxCollider3DC->GetBoxCollider()->GetCustomSize().x && mParentActor->GetTransform().GetWorldTransform().GetTranslation().x + mParentActor->GetTransform().GetWorldTransform().GetScale().x * mCustomScale.x > wall->GetTransform().GetWorldTransform().GetTranslation().x - wall->GetTransform().GetWorldTransform().GetScale().x * boxCollider3DC->GetBoxCollider()->GetCustomSize().x
                            && mParentActor->GetTransform().GetWorldTransform().GetTranslation().z < wall->GetTransform().GetWorldTransform().GetTranslation().z + wall->GetTransform().GetWorldTransform().GetScale().z * boxCollider3DC->GetBoxCollider()->GetCustomSize().z && mParentActor->GetTransform().GetWorldTransform().GetTranslation().z + mParentActor->GetTransform().GetWorldTransform().GetScale().z * mCustomScale.z > wall->GetTransform().GetWorldTransform().GetTranslation().z - wall->GetTransform().GetWorldTransform().GetScale().z * boxCollider3DC->GetBoxCollider()->GetCustomSize().z)
                        {
                            return true;
                        }
                    }
                }
            }
        }
        if (mParentActor != actor)
        {
            for (Components* component : actor->GetAllComponent())
            {
                if (DoomBoxCollider3DC* boxCollider3DC = dynamic_cast<DoomBoxCollider3DC*>(component))
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

    }

    return false;
}

Vector3 DoomBoxCollider3DC::GetDistance()
{
    for (Actor* actor : mOwner->GetScene()->GetAllActor())
    {
        if (mParentActor != actor)
        {
            for (Components* component : actor->GetAllComponent())
            {
                if (DoomBoxCollider3DC* boxCollider3DC = dynamic_cast<DoomBoxCollider3DC*>(component))
                {
                    if (mParentActor->GetTransform().GetPosition().y < actor->GetTransform().GetPosition().y + actor->GetTransform().GetScale().y * boxCollider3DC->GetCustomSize().y && mParentActor->GetTransform().GetPosition().y + mParentActor->GetTransform().GetScale().y * mCustomScale.y > actor->GetTransform().GetPosition().y
                        && mParentActor->GetTransform().GetPosition().x < actor->GetTransform().GetPosition().x + actor->GetTransform().GetScale().x * boxCollider3DC->GetCustomSize().x && mParentActor->GetTransform().GetPosition().x + mParentActor->GetTransform().GetScale().x * mCustomScale.x > actor->GetTransform().GetPosition().x
                        && mParentActor->GetTransform().GetPosition().z < actor->GetTransform().GetPosition().z + actor->GetTransform().GetScale().z * boxCollider3DC->GetCustomSize().z && mParentActor->GetTransform().GetPosition().z + mParentActor->GetTransform().GetScale().z * mCustomScale.z > actor->GetTransform().GetPosition().z)
                    {

                        return mParentActor->GetTransform().GetPosition() - actor->GetTransform().GetPosition();
                    }
                }
            }
        }
    }
}

Actor* DoomBoxCollider3DC::GetCollideActor()
{
    for (Actor* actor : mOwner->GetScene()->GetAllActor())
    {
        if (mParentActor != actor)
        {
            for (Components* component : actor->GetAllComponent())
            {
                if (DoomBoxCollider3DC* boxCollider3DC = dynamic_cast<DoomBoxCollider3DC*>(component))
                {
                    if (mParentActor->GetTransform().GetPosition().y < actor->GetTransform().GetPosition().y + actor->GetTransform().GetScale().y * boxCollider3DC->GetCustomSize().y && mParentActor->GetTransform().GetPosition().y + mParentActor->GetTransform().GetScale().y * mCustomScale.y > actor->GetTransform().GetPosition().y
                        && mParentActor->GetTransform().GetPosition().x < actor->GetTransform().GetPosition().x + actor->GetTransform().GetScale().x * boxCollider3DC->GetCustomSize().x && mParentActor->GetTransform().GetPosition().x + mParentActor->GetTransform().GetScale().x * mCustomScale.x > actor->GetTransform().GetPosition().x
                        && mParentActor->GetTransform().GetPosition().z < actor->GetTransform().GetPosition().z + actor->GetTransform().GetScale().z * boxCollider3DC->GetCustomSize().z && mParentActor->GetTransform().GetPosition().z + mParentActor->GetTransform().GetScale().z * mCustomScale.z > actor->GetTransform().GetPosition().z)
                    {

                        return actor;
                    }
                }
            }
        }
    }
}

void DoomBoxCollider3DC::Update()
{
}

void DoomBoxCollider3DC::Draw(RendererSDL& pRenderer)
{
}
