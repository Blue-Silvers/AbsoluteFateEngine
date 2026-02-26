#pragma once
#include "Components.h"
#include "Vector3.h"

class TheDescentMovingC : public Components
{
protected:
	Vector3 mSpeed;

public:
	TheDescentMovingC(Actor* pOwner, int pUpdateOrder = 100);
	TheDescentMovingC() = delete;
	TheDescentMovingC(const TheDescentMovingC&) = delete;
	TheDescentMovingC& operator= (const TheDescentMovingC&) = delete;

	Vector3 GetSpeed() const { return mSpeed; };
	void SetSpeed(Vector3 pSpeed);

	void Update() override;
	virtual void OnStart() {};
	virtual void OnEnd() {};
};