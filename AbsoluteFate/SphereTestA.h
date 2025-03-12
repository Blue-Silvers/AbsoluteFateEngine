#pragma once
#include "Actor.h"
#include "MeshC.h"

class SphereTestA : public Actor
{
private:
	MeshC* mMeshComponent;
	int mMouseDeltaX;
	int mMouseDeltaY;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
};

