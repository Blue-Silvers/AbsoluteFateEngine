#include "BowlingBallA.h"

#include "Asset.h"
#include "Time.h"
#include <iostream>

#include "Log.h"

void BowlingBallA::Start()
{
	mChildSphere = new BowlingBallVisualA();
	mChildSphere->AttachScene(GetScene());
	mChildSphere->Start();
	GetScene()->AddActor(mChildSphere);
	mTransform.RotateZInDegrees(-20);
	//mChildSphere->SetAngleRotationZ(-20);
}

void BowlingBallA::Update()
{
	Log::Info("" + std::to_string(mTransform.GetRotation().x) + ", " + std::to_string(mTransform.GetRotation().y) + ", " + std::to_string(mTransform.GetRotation().z));
	Log::Info("" + std::to_string(mTransform.GetRotationInDegrees().x) + ", " + std::to_string(mTransform.GetRotationInDegrees().y) + ", " + std::to_string(mTransform.GetRotationInDegrees().z));
	if (mChildSphere->GetBoxCollider()->OnCollide() != true)
	{
            // add new coordonate
        Vector3 newPosition = GetTransform().GetPosition() + ((GetTransform().Forward()* mVelocity)* 0.02);
        SetPosition(newPosition);
		//Log::Info("" + std::to_string(mTransform.GetRotationInDegrees().z/* - mChildSphere->GetTransform().GetRotationInDegrees().z*/));
		mChildSphere->SetAngleRotationY(mVelocity);
		

		mChildSphere->SetPosition(newPosition);
	}
	else
	{
		Log::Info("" + std::to_string(mChildSphere->GetBoxCollider()->GetDistance().x) + ", " + std::to_string(mChildSphere->GetBoxCollider()->GetDistance().y) + ", " + std::to_string(mChildSphere->GetBoxCollider()->GetDistance().z));
	}
}

void BowlingBallA::Destroy()
{
}
