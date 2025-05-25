#pragma once
#include "Actor.h"
#include "DoomHudA.h"
#include "AnimatedSpriteC.h"
#include "DoomGunA.h"
#include "DoomBoxCollider3DC.h"

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
	float mSensitivity = 0.05F;
	float mShootRange = 50;
	int lifePoint = 3;

	DoomHudA* mHud;
	bool mSetHud = false;

	DoomGunA* mGun;
	float mShootCooldown = 35;
	float mActualShootCooldown = 35;
	bool mCanShootAgain = true;

	DoomAnimState mAnimState = DoomAnimState::Idle;

	DoomBoxCollider3DC* mBoxCollider;

protected:
	bool mCanHorizontalMove = true, mCanVerticalMove = true;

public:
	void SetSensitivity(float pSensi);
	float GetSensitivity();
	void Start()override;
	void Update()override;
	void Destroy()override;

	void Shoot();
	void Interact();
	void TakeDamage();
	void WalkAnim();
	void IdleAnim();
	inline bool GetCanShootAgain() { return mCanShootAgain; };
	inline DoomGunA* GetGun() { return mGun; };
};

