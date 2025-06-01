#pragma once

#include "IInputListener.h"
#include "MovingC.h"

//Base for FPS constroller
class FPSController : public MovingC, public IInputListener
{
private:
	float mMoveSpeed = 12;

	bool wireframe = true;

public:
	FPSController(Actor* pActor);
	bool changeAnim = false;
	void OnNotify(SDL_Event& pEvent) override;

	//Getter & Setter
	float GetMoveSpeed() { return mMoveSpeed; }
	void SetMoveSpeed(float pMoveSpeed) { mMoveSpeed = pMoveSpeed; }
};