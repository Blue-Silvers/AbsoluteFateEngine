#pragma once
#include "Actor.h"
#include "MeshC.h" 
#include "DoomBoxCollider3DC.h"

class DoomEnemyA : public Actor
{
private:
	MeshC* mMeshComponent;
	Shader mTessVertexShader, mTessFragShader, mTessControlShader, mTessEvalShader;
	ShaderProgram mTessProgram;
	
	Actor* mTarget;

	DoomBoxCollider3DC* mBoxCollider;

	float mShootingRange = 20;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
	void LookAt(Actor* pTarget);
	void Shoot();

	/*	Getter \ Setter	*/
	inline Actor* GetTarget() { return mTarget; };
	inline void SetTarget(Actor* pTarget) { mTarget = pTarget; };
};