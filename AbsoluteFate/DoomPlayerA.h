#pragma once
#include "Actor.h"
#include "DoomHudA.h"
#include "AnimatedSpriteC.h"
#include "DoomGunA.h"

enum class DoomAnimState
{
	Idle,
	Walk,
	Shoot
};

class DoomPlayerA : public Actor
{
private:
	int mMouseDeltaX;
	int mMouseDeltaY;
	float mSensitivity = 0.05;
	float mShootRange = 20;
	int lifePoint = 3;

	DoomHudA* mHud;
	bool mSetHud = false;

	DoomGunA* mGun;
	float mShootCooldown = 50;
	float mActualShootCooldown = 50;
	bool mCanShootAgain = true;
	DoomAnimState mAnimState = DoomAnimState::Idle;
protected:
	bool mCanHorizontalMove = true, mCanVerticalMove = true;

public:
	void SetSensitivity(float pSensi);
	float GetSensitivity();
	void Start()override;
	void Update()override;
	void Destroy()override;

	void Shoot();
	void WalkAnim();
	void IdleAnim();
	inline bool GetCanShootAgain() { return mCanShootAgain; };
	inline DoomGunA* GetGun() { return mGun; };
};

