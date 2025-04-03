#pragma once
#include "Actor.h"

//#include <stdlib.h>
//#include <stdio.h>
//#define GLT_IMPLEMENTATION
//#include "gltext.h"
class CameraBowlingA : public Actor
{
private:
	GLTtext* text1;
	Matrix4Row view;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
	void Render()override;
};
