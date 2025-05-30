#pragma once
#include "Actor.h"
#include "MeshC.h" 
#include "DoomBoxCollider3DC.h"
#include "DoomEnnemyProjectil.h"

class DoomEnemyA : public Actor
{
private:
	MeshC* mMeshComponent;
	Shader mTessVertexShader, mTessFragShader, mTessControlShader, mTessEvalShader;
	ShaderProgram mTessProgram;
	
	Actor* mTarget;

	DoomBoxCollider3DC* mBoxCollider;

	float mShootingRange = 30;
	float mShootCooldown = 50;
	float mActualShootCooldown = 30;
	bool mCanShootAgain = true;

	vector<DoomEnnemyProjectil*> mCurrentProjectils;

	int mLife = 3;

	float mHitAnimTime = 20;

public:
	void Start()override;
	void Restart();
	void Update()override;
	void Destroy()override;
	void LookAt(Actor* pTarget);
	void Shoot();
	void TakeDamage();

	/*	Getter \ Setter	*/
	inline Actor* GetTarget() { return mTarget; };
	inline void SetTarget(Actor* pTarget) { mTarget = pTarget; };
};