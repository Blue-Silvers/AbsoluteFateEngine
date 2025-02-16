#pragma once
#pragma once
#include "Components.h"
#include "Vector2D.h"

class MovingC : public Components
{
protected:
	Vector2D mSpeed;

public:
	MovingC(Actor* pOwner, int pUpdateOrder = 100);
	MovingC() = delete;
	MovingC(const MovingC&) = delete;
	MovingC& operator= (const MovingC&) = delete;

	Vector2D GetSpeed() const { return mSpeed; }
	void SetSpeed(Vector2D pSpeed);

	void Update() override;
};

