#pragma once
#include "Actor.h"
#include "MeshC.h"

class SphereTestA : public Actor
{
private:
	MeshC* mMeshComponent;
	Mesh mMesh;
public:
	Scene* GetScene()
	{
		return mSceneAttached;
	};
	void Start()override;
	void Update()override;
	void Destroy()override;
};

