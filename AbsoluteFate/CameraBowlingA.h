#pragma once
#include "Actor.h"

class CameraBowlingA : public Actor
{
private:
	Matrix4Row view;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
	void Render()override;
};