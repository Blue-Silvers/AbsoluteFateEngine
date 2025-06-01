#pragma once
#include "Actor.h"
#include "MeshC.h"
#include "BoxCollider3DC.h"
#include "BoxCollider3DBowlingC.h"

class BowlingBallVisualA : public Actor
{
private:
	MeshC* mMeshComponent;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
	void SetAngleRotationY(float angle) { mTransform.RotateYInDegrees(angle); };
	void SetAngleRotationZ(float angle) { mTransform.RotateZInDegrees(angle);};
	MeshC* GetMeshC() { return mMeshComponent; };
};