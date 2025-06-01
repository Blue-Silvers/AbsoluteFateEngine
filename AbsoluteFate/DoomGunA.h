#pragma once
#include "Actor.h"
#include "AnimatedSpriteC.h"

class DoomGunA : public Actor
{
private:
	AnimatedSpriteC* mGun;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
};