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
}

void MovingC::Update()
{
    if (!Maths::NearZero(mSpeed.GetMagnitude()))
    {
        Vector2D newPosition = ((mOwner->GetTransform2D().Right().x * mSpeed.x + mOwner->GetTransform2D().Up().x * mSpeed.y) * Time::deltaTime + mOwner->GetTransform2D().GetPosition().x
                            , (mOwner->GetTransform2D().Right().y * mSpeed.x + mOwner->GetTransform2D().Up().y * mSpeed.y) * Time::deltaTime) + mOwner->GetTransform2D().GetPosition().y;
        mOwner->SetPosition(newPosition);
    }
}
