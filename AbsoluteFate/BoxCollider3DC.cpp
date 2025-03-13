#include "BoxCollider3DC.h"

BoxCollider3DC::BoxCollider3DC(Actor* pParentActor) : Components(pParentActor, 0), mParentActor(pParentActor), mCustomScale(pParentActor->GetTransform().GetScale())
{

}

bool BoxCollider3DC::OnCollide() const
{
    for (Actor* actor : mOwner->GetScene()->GetAllActor())
    {
        if (mParentActor != actor)
        {
            for (Components* component : actor->GetAllComponent())
            {
                if (BoxCollider3DC* boxCollider3DC = dynamic_cast<BoxCollider3DC*>(component))
                {
                    if (mParentActor->GetTransform().GetPosition().y < actor->GetTransform().GetPosition().y + actor->GetTransform().GetScale().y * boxCollider3DC->GetCustomSize().y && mParentActor->GetTransform().GetPosition().y + mParentActor->GetTransform().GetScale().y * mCustomScale.y > actor->GetTransform().GetPosition().y
                        && mParentActor->GetTransform().GetPosition().x < actor->GetTransform().GetPosition().x + actor->GetTransform().GetScale().x * boxCollider3DC->GetCustomSize().x && mParentActor->GetTransform().GetPosition().x + mParentActor->GetTransform().GetScale().x * mCustomScale.x > actor->GetTransform().GetPosition().x
                        && mParentActor->GetTransform().GetPosition().z < actor->GetTransform().GetPosition().z + actor->GetTransform().GetScale().z * boxCollider3DC->GetCustomSize().z && mParentActor->GetTransform().GetPosition().z + mParentActor->GetTransform().GetScale().z * mCustomScale.z > actor->GetTransform().GetPosition().z)
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

Vector3 BoxCollider3DC::GetDistance()
{
    for (Actor* actor : mOwner->GetScene()->GetAllActor())
    {
        if (mParentActor != actor)
        {
            for (Components* component : actor->GetAllComponent())
            {
                if (BoxCollider3DC* boxCollider3DC = dynamic_cast<BoxCollider3DC*>(component))
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

void BoxCollider3DC::Update()
{
}

void BoxCollider3DC::Draw(RendererSDL& pRenderer)
{
}
