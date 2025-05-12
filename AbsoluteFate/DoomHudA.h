#pragma once
#include "Actor.h"
#include "OpenGlPictureA.h"
#include "Asset.h"

class DoomHudA : public Actor
{
private:
	vector<OpenGlPictureA*> mIconList;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;

	inline vector<OpenGlPictureA*> GetIconList() { return mIconList; };
};

