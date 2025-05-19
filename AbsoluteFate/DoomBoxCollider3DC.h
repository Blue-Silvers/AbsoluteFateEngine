#pragma once
#include "Components.h"
#include "Transform.h"
#include "Actor.h"

struct DoomHitCollider
{
    bool isCollid;
    Actor* parentActor;
    Actor* collideActor;
    bool isOverlap;
    Vector3 distance;
};

class DoomBoxCollider3DC : public Components
{
private:
    Actor* mParentActor;
    Vector3 mCustomScale;
    bool mIsOverlap = false;
    DoomHitCollider mHitCollider;

public:
    DoomBoxCollider3DC(Actor* pParentActor);
    DoomBoxCollider3DC() = delete;
    DoomBoxCollider3DC(const DoomBoxCollider3DC&) = delete;

    virtual void OnStart()
    {
        mParentActor = mOwner;
    };

    //Check if this collider box hit another collider box
    bool OnCollide() const;
    DoomBoxCollider3DC* GetBoxCollider() { return this; };
    Vector3 GetDistance();
    void SetCustomSize(Vector3 pSize) { mCustomScale = pSize; }
    Vector3 GetCustomSize() { return mCustomScale; }
    Actor* GetCollideActor();

    DoomHitCollider GetOnCollide();
    DoomHitCollider GetOnCollideByLineTrace(Vector3 lineTraceEndPos);

    inline bool GetIsOverlap() { return mIsOverlap; };
    inline void SetIsOverlap(bool pIsOverlap) { mIsOverlap = pIsOverlap; };

    virtual void Update();
    virtual void Draw(RendererSDL& pRenderer);
    virtual void OnEnd() {};
};