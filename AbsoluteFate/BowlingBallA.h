#pragma once
#include "Actor.h"
#include "BowlingBallVisualA.h"

class BowlingBallA : public Actor
{
private:
	BowlingBallVisualA* mChildSphere;
	float mVelocity = 10;
	//MeshC* mMeshComponent;
	BoxCollider3DC* mBoxCollider;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
	BoxCollider3DC* GetBoxCollider() { return mBoxCollider; };
};

