#pragma once
#include "Actor.h"
#include "OpenGlPictureA.h"

class BowlingUISkinA : public Actor
{
private:
	std::vector<OpenGlPictureA*> mIconList;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
};

