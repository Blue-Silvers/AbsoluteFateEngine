#pragma once
#include "Actor.h"
#include "MeshC.h"
#include "DoomBoxCollider3DC.h"

class DoomEnnemyProjectil : public Actor
{
private:
	MeshC* mMeshComponent;
	DoomBoxCollider3DC* mBoxCollider;
	Vector3 mForward = Vector3(0,0,0);
	float mVelocity = 30;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;

	void HitSomething();
	inline void SetForward(Vector3 pForward) { mForward = pForward; }
};