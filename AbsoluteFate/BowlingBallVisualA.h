#pragma once
#include "Actor.h"
#include "MeshC.h"
#include "BoxCollider3DC.h"

class BowlingBallVisualA : public Actor
{
private:
	MeshC* mMeshComponent;
	BoxCollider3DC* mBoxCollider;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
	void SetAngleRotationY(float angle) { mTransform.RotateYInDegrees(angle); };
	void SetAngleRotationZ(float angle) { mTransform.RotateZInDegrees(angle);};
	BoxCollider3DC* GetBoxCollider() { return mBoxCollider; };
};

