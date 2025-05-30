#pragma once
#include "Actor.h"
#include "FPSController.h"

class CameraA : public Actor
{
private:
	int mMouseDeltaX;
	int mMouseDeltaY;
	float mSensitivity = 0.05F;

	FPSController* movement;

protected:
	bool mCanHorizontalMove = true, mCanVerticalMove = true;

public:
	void SetSensitivity(float pSensi);
	float GetSensitivity();
	inline FPSController* GetMovementComponent() {	return movement; };
	void Start()override;
	void Update()override;
	void Destroy()override;
};

