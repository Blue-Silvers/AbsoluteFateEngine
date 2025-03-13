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
	//mTransform.RotateZInDegrees(mStartRotation);
	//mChildSphere->SetAngleRotationZ(-20);

	mBowlingControllerC = new BowlingControllerC(this);
	AddComponent(mBowlingControllerC);

	mChildSphere->SetAngleRotationY(0);
	
}

void BowlingBallA::Update()
{
	if (mIsLunching)
	{
		// add Movement
		Vector3 newPosition = GetTransform().GetPosition() + ((GetTransform().Forward() * mVelocity) * 0.02);
		SetPosition(newPosition);
		//Log::Info("" + std::to_string(mTransform.GetRotationInDegrees().z/* - mChildSphere->GetTransform().GetRotationInDegrees().z*/));
		mChildSphere->SetAngleRotationY(mVelocity);
		mChildSphere->SetPosition(newPosition);

		if (mChildSphere->GetBoxCollider()->OnCollide() == true)
		{
			for (string tag : mChildSphere->GetBoxCollider()->GetCollideActor()->GetTags())
			{
				if (tag == "bowlingPin")
				{
					mVelocity = 0;
					Log::Info("" + std::to_string(mChildSphere->GetBoxCollider()->GetDistance().x) + ", " + std::to_string(mChildSphere->GetBoxCollider()->GetDistance().y) + ", " + std::to_string(mChildSphere->GetBoxCollider()->GetDistance().z));
				}
				else
				{
					ChangeRotation();
				}
			}
		}
	}
	else 
	{
		mChildSphere->SetPosition(GetTransform().GetPosition());
		mStartRotation += mStartRotationSpeed;
		if (mStartRotation > mMaxStartRotation)
		{
			mStartRotation = mMaxStartRotation;
			mStartRotationSpeed = -mStartRotationSpeed;
		}
		else if (mStartRotation < mMinStartRotation)
		{
			mStartRotation = mMinStartRotation;
			mStartRotationSpeed = -mStartRotationSpeed;
		}
		Log::Info("" + std::to_string(mStartRotation));
	}
}

void BowlingBallA::Destroy()
{
	delete mBowlingControllerC;
	delete mChildSphere;
}

void BowlingBallA::ChangeRotation()
{
	mStartRotation = -mStartRotation;
	mTransform.RotateZInDegrees(mStartRotation);
	mTransform.RotateZInDegrees(mStartRotation);
}

void BowlingBallA::LunchBall()
{
	mIsLunching = true;
	mTransform.RotateZInDegrees(mStartRotation);
}
