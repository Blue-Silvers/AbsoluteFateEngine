#pragma once
#include "Actor.h"

class TheWallA : public Actor
{
private:

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
};

