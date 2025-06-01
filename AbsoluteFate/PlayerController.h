#pragma once
#include "IInputListener.h"
#include "MovingC.h"

//Base for create a player controller
class PlayerController : public MovingC, public IInputListener
{
private:
	float mMoveSpeed;

public:
	PlayerController(Actor* pActor);
	bool changeAnim = false;
	void OnNotify(SDL_Event& pEvent) override;

	//Getter & Setter
	float GetMoveSpeed() { return mMoveSpeed; }
	void SetMoveSpeed(float pMoveSpeed) { mMoveSpeed = pMoveSpeed; }
};