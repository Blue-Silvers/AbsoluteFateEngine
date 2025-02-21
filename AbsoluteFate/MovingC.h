#pragma once
#pragma once
#include "Components.h"
#include "Vector2.h"

enum Direction
{
	MOVE_UP,
	MOVE_DOWN,
	MOVE_RIGHT,
	MOVE_LEFT,
	MOVE_STOP
};

class MovingC : public Components
{
protected:
	Vector2 mSpeed;
	Direction currentDirection = MOVE_STOP;
	Direction lastDirection = MOVE_STOP;

public:
	MovingC(Actor* pOwner, int pUpdateOrder = 100);
	MovingC() = delete;
	MovingC(const MovingC&) = delete;
	MovingC& operator= (const MovingC&) = delete;

	Vector2 GetSpeed() const { return mSpeed; }
	Direction GetCurrentDirection() const { return currentDirection; }
	void SetSpeed(Vector2 pSpeed);

	void Update() override;
	virtual void OnStart() {};
	virtual void OnEnd() {};
};

