#pragma once
#include "Actor.h"
#include "PinA.h"

class SetOfPinA : public Actor
{
private:
	vector<PinA*> mPinList;
	bool restart = true;
	float timeBeforeRestart = 20;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
	vector<PinA*> GetPinList() { return mPinList; };
};
