#pragma once
#include "Actor.h"

class DeathAngelA : public Actor
{
private:

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
};

