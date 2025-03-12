#pragma once
#include "Components.h"
#include "Transform.h"
#include "Actor.h"

class BoxCollider3DC : public Components
{
private:
    Actor* mParentActor;

public:
    BoxCollider3DC(Actor* pParentActor);
    BoxCollider3DC() = delete;
    BoxCollider3DC(const BoxCollider3DC&) = delete;

    virtual void OnStart()
    {
        mParentActor = mOwner;
    };

    //Check if this collider box hit another collider box
    bool OnCollide() const;
    BoxCollider3DC* GetBoxCollider() { return this; };
    Vector3 GetDistance();

    virtual void Update();
    virtual void Draw(RendererSDL& pRenderer);
    virtual void OnEnd() {};
};

