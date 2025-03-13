#pragma once
#include "Actor.h"
#include "PinA.h"

class SetOfPinA : public Actor
{
private:
	vector<PinA*> mPinList;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
	vector<PinA*> GetPinList() { return mPinList; };
};
