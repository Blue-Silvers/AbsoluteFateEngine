#pragma once
#include "IInputListener.h"
#include "MovingC.h"

class DoomController : public MovingC, public IInputListener
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

