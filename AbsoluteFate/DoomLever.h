#pragma once
#include "Actor.h"
#include "MeshC.h" 
#include "DoomDoor.h"

class DoomLever : public Actor
{
private:
	MeshC* mMeshComponent;
	Shader mTessVertexShader, mTessFragShader, mTessControlShader, mTessEvalShader;
	ShaderProgram mTessProgram;
	bool mLeverActive = false;
	DoomDoor* mDoorLinked;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;

	/*	Getter \ Setter	*/
	inline bool GetLeverActive() { return mLeverActive; };
	inline void SetLeverActive(bool isActive) { mLeverActive = isActive; };
	inline DoomDoor* GetDoorLinked() { return mDoorLinked; };
	inline void SetDoorLinked(DoomDoor* pDoor) { mDoorLinked = pDoor; };
};

