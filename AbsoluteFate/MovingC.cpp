#include "MovingC.h"
#include "Actor.h"
#include "Time.h"
#include "Vector2.h"
#include "Maths.h"
#include "BoxCollider2DC.h"

#include "Log.h"

MovingC::MovingC(Actor* pOwner, int pUpdateOrder) : Components(pOwner, pUpdateOrder), 
                                                    mSpeed(Vector3::zero)
{
}

void MovingC::SetSpeed(Vector3 pSpeed)
{
    mSpeed = pSpeed;
    lastDirection = currentDirection;
    if (mSpeed.x > 0)
    {
        currentDirection = MOVE_FORWARD;
    }
    else if (mSpeed.x < 0)
    {
        currentDirection = MOVE_BACK;
    }
    else if (mSpeed.y > 0)
    {
        currentDirection = MOVE_RIGHT;
    }
    else if (mSpeed.y < 0)
    {
        currentDirection = MOVE_LEFT;
    }
    else if (mSpeed.z > 0)
    {
        currentDirection = MOVE_UP;
        
    }
    else if (mSpeed.z < 0)
    {
        currentDirection = MOVE_DOWN;
    }
}

void MovingC::Update()
{
    Vector3 forwardVector = mOwner->GetTransform().Forward();
    Vector3 rightVector = mOwner->GetTransform().Right();
    Vector3 upVector = mOwner->GetTransform().Up();

    if (mSpeed.x != 0 || mSpeed.y != 0 || mSpeed.z != 0)
    {
        // add forward
        forwardVector *= mSpeed.x;
        forwardVector *= Time::deltaTime;
        // add right
        rightVector *= mSpeed.y;
        rightVector *= Time::deltaTime;
        // add up
        upVector *= mSpeed.z;
        upVector *= Time::deltaTime;
        // add new coordonate
        Vector3 newPosition = mOwner->GetTransform().GetPosition() + (forwardVector + rightVector + upVector);
        //newPosition += (forwardVector + rightVector + upVector); // add forward
        //newPosition += rightVector; // add right
        //newPosition += upVector; // add up
        Log::Info("" + std::to_string(newPosition.x) + ", " + std::to_string(newPosition.y) + ", " + std::to_string(newPosition.z));
        mOwner->SetPosition(newPosition);
        
        //keep last position 
        /*Vector3 lastPosition = mOwner->GetTransform().GetPosition();
        newPosition -= forwardVector; // add forward
        lastPosition -= rightVector; // add right
        lastPosition -= upVector; // add up*/

        //mOwner->SetPosition(newPosition);

        //teleport to the last position if collide another collider box
        /*for (Components* component : mOwner->GetAllComponent())
        {
            if (BoxCollider2DC* pBoxCollider2DC = dynamic_cast<BoxCollider2DC*>(component))
            {
                if (pBoxCollider2DC->OnCollide() == true)
                {
                    mOwner->SetPosition(lastPosition);
                }
            }
        }*/

    }

}
