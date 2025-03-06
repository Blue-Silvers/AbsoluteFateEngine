#pragma once
#include "Actor.h"

class CubeTestA : public Actor
{
private:

public:
	Scene* GetScene()
	{
		return mSceneAttached;
	};
	void Start()override;
	void Update()override;
	void Destroy()override;
};

