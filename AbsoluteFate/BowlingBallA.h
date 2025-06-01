#pragma once
#include "Actor.h"
#include "BowlingBallVisualA.h"
#include "BowlingControllerC.h"
#include "MeshC.h"

class BowlingBallA : public Actor
{
private:
	BowlingControllerC* mBowlingControllerC;
	BowlingBallVisualA* mChildSphere;
	float mVelocity = 15;
	bool mIsLunching = false;
	BoxCollider3DBowlingC* mBoxCollider;

	float mStartRotation = 0;
	float mStartRotationSpeed = 0.4F;
	float mMaxStartRotation = 20;
	float mMinStartRotation = -20;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
	BoxCollider3DBowlingC* GetBoxCollider() { return mBoxCollider; };
	void ChangeRotation();
	void LunchBall();
	float GetStartRotation() { return mStartRotation; };
	bool GetIsLunch() { return mIsLunching; };
	MeshC* GetMeshC() { return mChildSphere->GetMeshC(); };
};