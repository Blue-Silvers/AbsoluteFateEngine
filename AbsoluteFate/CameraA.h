#pragma once
#include "Actor.h"

class CameraA : public Actor
{
private:
	int mMouseDeltaX;
	int mMouseDeltaY;
public:
	Scene* GetScene()
	{
		return mSceneAttached;
	};
	void Start()override;
	void Update()override;
	void Destroy()override;
};

