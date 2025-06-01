#pragma once
#include "Components.h"
#include "Vector3.h"

class DoomMovingC : public Components
{
protected:
	Vector3 mSpeed;

public:
	DoomMovingC(Actor* pOwner, int pUpdateOrder = 100);
	DoomMovingC() = delete;
	DoomMovingC(const DoomMovingC&) = delete;
	DoomMovingC& operator= (const DoomMovingC&) = delete;

	Vector3 GetSpeed() const { return mSpeed; };
	void SetSpeed(Vector3 pSpeed);

	void Update() override;
	virtual void OnStart() {};
	virtual void OnEnd() {};
};