#include "MovingC.h"
#include "Actor.h"
#include "Time.h"
#include "Vector2D.h"
#include "Maths.h"
MovingC::MovingC(Actor* pOwner, int pUpdateOrder) : Components(pOwner, pUpdateOrder), 
                                                    mSpeed(0.0f)
{
}

void MovingC::SetSpeed(Vector2D pSpeed)
{
    mSpeed = pSpeed;
    lastDirection = currentDirection;
    if (mSpeed.x > 0)
    {
        currentDirection = MOVE_RIGHT;
    }
    else if (mSpeed.x < 0)
    {
        currentDirection = MOVE_LEFT;
    }
    else if (mSpeed.y > 0)
    {
        currentDirection = MOVE_UP;
    }
    else if (mSpeed.y < 0)
    {
        currentDirection = MOVE_DOWN;
    }
}

void MovingC::Update()
{
    if (!Maths::NearZero(mSpeed.GetMagnitude()))
    {
        // add right
        Vector2D rightVector = mOwner->GetTransform2D().Right();
        rightVector *= mSpeed.x;
        rightVector *= Time::deltaTime;
        // add up
        Vector2D upVector = mOwner->GetTransform2D().Up();
        upVector *= mSpeed.y;
        upVector *= Time::deltaTime;
        // add new coordonate
        Vector2D newPosition = mOwner->GetTransform2D().GetPosition();
        newPosition += rightVector; // add right
        newPosition += upVector; // add up

        mOwner->SetPosition(newPosition);
    }

}
