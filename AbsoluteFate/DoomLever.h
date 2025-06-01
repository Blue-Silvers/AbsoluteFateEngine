#pragma once
#include "Actor.h"
#include "MeshC.h" 
#include "DoomDoor.h"
#include "DoomBoxCollider3DC.h"

class DoomLever : public Actor
{
private:
	MeshC* mMeshComponent;
	Shader mTessVertexShader, mTessFragShader, mTessControlShader, mTessEvalShader;
	ShaderProgram mTessProgram;
	bool mLeverActive = false;
	DoomDoor* mDoorLinked;
	DoomBoxCollider3DC* mBoxCollider;

public:
	void Start()override;
	void Restart();
	void Update()override;
	void Destroy()override;

	/*	Getter \ Setter	*/
	inline bool GetLeverActive() { return mLeverActive; };
	inline void SetLeverActive(bool isActive) { mLeverActive = isActive; };
	inline DoomDoor* GetDoorLinked() { return mDoorLinked; };
	inline void SetDoorLinked(DoomDoor* pDoor) { mDoorLinked = pDoor; };
};