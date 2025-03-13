#pragma once
#include "Actor.h"
#include "MeshC.h"

class BowlingPathA : public Actor
{
private:
	MeshC* mMeshComponent;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
};

