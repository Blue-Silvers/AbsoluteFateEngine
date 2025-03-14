#pragma once
#include "Actor.h"
#include "IInputListener.h"
#include "Components.h"

class BowlingControllerC : public Components, public IInputListener
{
private:

public:
	BowlingControllerC(Actor* pActor);
	void OnNotify(SDL_Event& pEvent) override;

	void Update() override {};
	void OnStart() override {};
	void OnEnd() override {};
};

