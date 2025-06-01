#pragma once
#include "Actor.h"
#include "MeshC.h"
#include "BoxCollider3DBowlingC.h"

class BowlingBorderA : public Actor
{
private:
	MeshC* mMeshComponent;
	BoxCollider3DBowlingC* mBoxCollider;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
	BoxCollider3DBowlingC* GetBoxCollider() { return mBoxCollider; };
};