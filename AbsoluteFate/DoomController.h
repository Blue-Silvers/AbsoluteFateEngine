#pragma once
#include "IInputListener.h"
#include "DoomMovingC.h"

class DoomController : public DoomMovingC, public IInputListener
{
private:
	float mMoveSpeed = 12;

	bool wireframe = true;

public:
	DoomController(Actor* pActor);
	bool changeAnim = false;
	void OnNotify(SDL_Event& pEvent) override;
	float GetMoveSpeed() { return mMoveSpeed; }
	void SetMoveSpeed(float pMoveSpeed) { mMoveSpeed = pMoveSpeed; }
};

