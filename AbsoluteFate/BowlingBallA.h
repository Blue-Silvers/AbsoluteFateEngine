#pragma once
#include "Actor.h"
#include "BowlingBallVisualA.h"
#include "BowlingControllerC.h"

class BowlingBallA : public Actor
{
private:
	BowlingControllerC* mBowlingControllerC;
	BowlingBallVisualA* mChildSphere;
	float mVelocity = 10;
	bool mIsLunching = false;
	BoxCollider3DC* mBoxCollider;

	float mStartRotation = 0;
	float mStartRotationSpeed = 0.3;
	float mMaxStartRotation = 20;
	float mMinStartRotation = -20;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
	BoxCollider3DC* GetBoxCollider() { return mBoxCollider; };
	void ChangeRotation();
	void LunchBall();
	float GetStartRotation() { return mStartRotation; };
	bool GetIsLunch() { return mIsLunching; };
};

