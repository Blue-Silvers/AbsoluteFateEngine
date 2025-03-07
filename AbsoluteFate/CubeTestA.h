#pragma once
#include "Actor.h"
#include "MeshC.h"

class CubeTestA : public Actor
{
private:
	MeshC* mMeshComponent;
public:
	Scene* GetScene()
	{
		return mSceneAttached;
	};
	void Start()override;
	void Update()override;
	void Destroy()override;
};

