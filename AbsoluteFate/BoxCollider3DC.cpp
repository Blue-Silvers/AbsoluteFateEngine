#include "BoxCollider3DC.h"

BoxCollider3DC::BoxCollider3DC(Actor* pParentActor) : Components(pParentActor, 0), mParentActor(pParentActor)
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
                    if (mParentActor->GetTransform().GetPosition().y < actor->GetTransform().GetPosition().y + actor->GetTransform().GetScale().y*2 && mParentActor->GetTransform().GetPosition().y + mParentActor->GetTransform().GetScale().y * 2 > actor->GetTransform().GetPosition().y
                        && mParentActor->GetTransform().GetPosition().x < actor->GetTransform().GetPosition().x + actor->GetTransform().GetScale().x * 2 && mParentActor->GetTransform().GetPosition().x + mParentActor->GetTransform().GetScale().x * 2 > actor->GetTransform().GetPosition().x
                        && mParentActor->GetTransform().GetPosition().z < actor->GetTransform().GetPosition().z + actor->GetTransform().GetScale().z * 2 && mParentActor->GetTransform().GetPosition().z + mParentActor->GetTransform().GetScale().z * 2 > actor->GetTransform().GetPosition().z)
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
                    if (mParentActor->GetTransform().GetPosition().y < actor->GetTransform().GetPosition().y + actor->GetTransform().GetScale().y * 2 && mParentActor->GetTransform().GetPosition().y + mParentActor->GetTransform().GetScale().y * 2 > actor->GetTransform().GetPosition().y
                        && mParentActor->GetTransform().GetPosition().x < actor->GetTransform().GetPosition().x + actor->GetTransform().GetScale().x * 2 && mParentActor->GetTransform().GetPosition().x + mParentActor->GetTransform().GetScale().x * 2 > actor->GetTransform().GetPosition().x
                        && mParentActor->GetTransform().GetPosition().z < actor->GetTransform().GetPosition().z + actor->GetTransform().GetScale().z * 2 && mParentActor->GetTransform().GetPosition().z + mParentActor->GetTransform().GetScale().z * 2 > actor->GetTransform().GetPosition().z)
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
