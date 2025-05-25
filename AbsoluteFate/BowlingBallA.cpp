#include "BowlingBallA.h"

#include "Asset.h"
#include "Time.h"
#include "PinA.h"
#include <iostream>

#include "Log.h"

void BowlingBallA::Start()
{
	mChildSphere = new BowlingBallVisualA();
	mChildSphere->AttachScene(GetScene());
	mChildSphere->Start();
	GetScene()->AddActor(mChildSphere);
	SetPosition(Vector3(0, 0, 0));

	mBowlingControllerC = new BowlingControllerC(this);
	AddComponent(mBowlingControllerC);

	mChildSphere->SetAngleRotationY(0);
	
	mBoxCollider = new BoxCollider3DBowlingC(this);
	mBoxCollider->SetCustomSize(Vector3(2, 2, 2));
	AddComponent(mBoxCollider);
}

void BowlingBallA::Update()
{
	if (mIsLunching)
	{
		// add Movement
		Vector3 newPosition = GetTransform().GetPosition() + ((GetTransform().Forward() * mVelocity) * 0.02F);
		SetPosition(newPosition);
		mChildSphere->SetAngleRotationY(mVelocity);
		mChildSphere->SetPosition(newPosition);
		if (GetBoxCollider()->OnCollide() == true)
		{
			bool hitPin = false;
			for (string tag : GetBoxCollider()->GetCollideActor()->GetTags())
			{
				if (tag == "bowlingPin")
				{
					hitPin = true;

				}
			}
			if (hitPin == true)
			{
				if (PinA* pinA = dynamic_cast<PinA*>(GetBoxCollider()->GetCollideActor()))
				{
					pinA->AddForce(GetBoxCollider()->GetDistance());
				}
			}
			else
			{
				ChangeRotation();
			}
		}
		
		//Restart
		if (mChildSphere->GetTransform().GetPosition().x > 65) 
		{
			SetPosition(Vector3(GetTransform().GetPosition().x, GetTransform().GetPosition().y, GetTransform().GetPosition().z - 0.2F));
			if (GetTransform().GetPosition().z < -15) 
			{
				mIsLunching = false;
				SetPosition(Vector3(0, 0, 0));
				mStartRotation = 0;
				SetRotation(Quaternion(0, 0, 0, 1));
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
	if (mIsLunching == false)
	{
		mTransform.RotateZInDegrees(mStartRotation);
	}
	mIsLunching = true;
}
