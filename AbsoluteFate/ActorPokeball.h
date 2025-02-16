#pragma once
#include "Actor.h"

class ActorPokeball : public Actor
{
private:

public:
	/*ActorPokeball();
	ActorPokeball(Transform2D pTransform2D, Scene* pScene);*/
	Scene* GetScene()
	{
		return mSceneAttached;
	};
	void Start()override;
	void Update()override;
	void Destroy()override;
};

