#pragma once
#include "Components.h"
#include "Vector3.h"

//Enum of current direction
enum Direction
{
	MOVE_FORWARD,
	MOVE_BACK,
	MOVE_UP,
	MOVE_DOWN,
	MOVE_RIGHT,
	MOVE_LEFT,
	MOVE_STOP
};

class MovingC : public Components
{
protected:
	Vector3 mSpeed;
	Direction currentDirection = MOVE_STOP;
	Direction lastDirection = MOVE_STOP;

public:
	//Constructor
	MovingC(Actor* pOwner, int pUpdateOrder = 100);
	MovingC() = delete;
	MovingC(const MovingC&) = delete;
	MovingC& operator= (const MovingC&) = delete;

	//Getter & Setter
	Vector3 GetSpeed() const { return mSpeed; }
	Direction GetCurrentDirection() const { return currentDirection; }
	void SetSpeed(Vector3 pSpeed);

	void Update() override;
	virtual void OnStart() {};
	virtual void OnEnd() {};
};