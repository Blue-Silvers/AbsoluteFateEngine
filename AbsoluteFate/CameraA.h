#pragma once
#include "Actor.h"

class CameraA : public Actor
{
private:
	int mMouseDeltaX;
	int mMouseDeltaY;
	float mSensitivity = 0.05;

protected:
	bool mCanHorizontalMove = true, mCanVerticalMove = true;

public:
	void SetSensitivity(float pSensi);
	float GetSensitivity();
	void Start()override;
	void Update()override;
	void Destroy()override;
};

