#pragma once
#include "Actor.h"
#include "MeshC.h"
#include "BoxCollider3DC.h"

class SphereTestA : public Actor
{
private:
	MeshC* mMeshComponent;
	BoxCollider3DC* mBoxCollider;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
	BoxCollider3DC* GetBoxCollider() { return mBoxCollider; };
	MeshC* GetMeshC() { return mMeshComponent; };
};

