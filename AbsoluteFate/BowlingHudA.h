#pragma once
#include "Actor.h"
#include "SphereTestA.h"
#include "OpenGlPictureA.h"

class BowlingHudA : public Actor
{
private:
	vector<OpenGlPictureA*> mIconList;
	vector<SphereTestA*> mSkinList;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
};