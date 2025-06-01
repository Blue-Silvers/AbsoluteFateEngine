#pragma once
#include "Components.h"
#include "Transform.h"
#include "Actor.h"

//Break collider info
struct HitCollider
{
    bool isCollid;
    Actor* parentActor;
    Actor* collideActor;
    bool isOverlap;
    Vector3 distance;
};

class BoxCollider3DC : public Components
{
private:
    Actor* mParentActor;
    Vector3 mCustomScale;
    bool mIsOverlap = false;
    HitCollider mHitCollider;

public:
    //Constructor
    BoxCollider3DC(Actor* pParentActor);
    BoxCollider3DC() = delete;
    BoxCollider3DC(const BoxCollider3DC&) = delete;

    virtual void OnStart()
    {
        mParentActor = mOwner;
    };

    //Check if this collider box hit another collider box
    bool OnCollide() const; //return true if collide
    Vector3 GetDistance(); //return only distance between hit collide and midle of object
    Actor* GetCollideActor(); //return only actor collide
    HitCollider GetOnCollide(); //return all collider info in struct
    HitCollider GetOnCollideByLineTrace(Vector3 lineTraceEndPos); //return all collider info in struct for linetrace
    HitCollider Linetrace(Vector3 pStartPoint, Vector3 pLineTraceDirection,float pRange); //return all collider info in struct whith linetrace
    
    //Getter & Setter
    BoxCollider3DC* GetBoxCollider() { return this; }; 
    void SetCustomSize(Vector3 pSize) { mCustomScale = pSize; }
    Vector3 GetCustomSize() { return mCustomScale; }
    inline bool GetIsOverlap() { return mIsOverlap; };
    inline void SetIsOverlap(bool pIsOverlap) { mIsOverlap = pIsOverlap; };

    virtual void Update();
    virtual void Draw(RendererSDL& pRenderer);
    virtual void OnEnd() {};
};