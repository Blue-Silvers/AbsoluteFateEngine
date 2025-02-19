#pragma once
#include "IInputListener.h"
#include "MovingC.h"

class PlayerController : public MovingC, public IInputListener
{
private:

public:
	PlayerController(Actor* pActor);
	bool changeAnim = false;
	void OnNotify(SDL_Event& pEvent) override;
};

