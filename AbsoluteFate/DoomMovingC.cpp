#include "DoomMovingC.h"

#include "Actor.h"
#include "Time.h"
#include "Vector2.h"
#include "Maths.h"
#include "DoomBoxCollider3DC.h"

#include "Log.h"

DoomMovingC::DoomMovingC(Actor* pOwner, int pUpdateOrder) : Components(pOwner, pUpdateOrder),
mSpeed(Vector3::zero)
{
}

void DoomMovingC::SetSpeed(Vector3 pSpeed)
{
    mSpeed = pSpeed;
}

void DoomMovingC::Update()
{
    Vector3 forwardVector = mOwner->GetTransform().Forward();
    Vector3 rightVector = mOwner->GetTransform().Right();

    if (mSpeed.x != 0 || mSpeed.y != 0 || mSpeed.z != 0)
    {
        // add forward
        forwardVector *= mSpeed.x;
        forwardVector *= Time::deltaTime;
        // add right
        rightVector *= mSpeed.y;
        rightVector *= Time::deltaTime;
        // keep last position 
        Vector3 lastPosition = mOwner->GetTransform().GetPosition();
        // add new coordonate
        Vector3 newPosition = mOwner->GetTransform().GetPosition() + (forwardVector + rightVector);

        Log::Info("" + std::to_string(newPosition.x) + ", " + std::to_string(newPosition.y) + ", " + std::to_string(newPosition.z));
        mOwner->SetPosition(newPosition);

        //teleport to the last position if collide another collider box
        for (Components* component : mOwner->GetAllComponent())
        {
            if (DoomBoxCollider3DC* boxCollider = dynamic_cast<DoomBoxCollider3DC*>(component))
            {
                if (boxCollider->OnCollide() == true)
                {
                    mOwner->SetPosition(lastPosition);
                }
            }
        }

    }

}
