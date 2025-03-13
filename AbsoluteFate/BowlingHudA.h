#pragma once
#include "Actor.h"

class BowlingHudA : public Actor
{
private:
	//SpriteC* mSprite = nullptr;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
};

