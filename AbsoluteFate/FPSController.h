#pragma once

#include "IInputListener.h"
#include "MovingC.h"

class FPSController : public MovingC, public IInputListener
{
private:
	float mMoveSpeed = 6;
public:
	FPSController(Actor* pActor);
	bool changeAnim = false;
	void OnNotify(SDL_Event& pEvent) override;
	float GetMoveSpeed() { return mMoveSpeed; }
	void SetMoveSpeed(float pMoveSpeed) { mMoveSpeed = pMoveSpeed; }
};

