#pragma once
#include "Components.h"
#include "Transform.h"
#include "Actor.h"

class BoxCollider3DC : public Components
{
private:
    Actor* mParentActor;
    Vector3 mCustomScale;

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
    void SetCustomSize(Vector3 pSize) { mCustomScale = pSize; }
    Vector3 GetCustomSize() { return mCustomScale; }
    Actor* GetCollideActor();

    virtual void Update();
    virtual void Draw(RendererSDL& pRenderer);
    virtual void OnEnd() {};
};

