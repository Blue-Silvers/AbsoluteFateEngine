#pragma once
#include "Actor.h"

class ActorPokeball : public Actor
{
private:

public:
	ActorPokeball(Transform2D pTransform2D, Scene* pScene);
	void Start()override;
	void Update()override;
	void Destroy()override;
};

