#pragma once
#include "Actor.h"
#include "MeshC.h"

class NightSkyBoxA : public Actor
{
private:
	MeshC* mMeshComponent;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
	MeshC* GetMeshC() { return mMeshComponent; };
};

