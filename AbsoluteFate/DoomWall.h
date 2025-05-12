#pragma once
#include "Actor.h"
#include "MeshC.h" 
#include "DoomBoxCollider3DC.h" 

class DoomWall : public Actor
{
private:
	MeshC* mMeshComponent;
	Shader mTessVertexShader, mTessFragShader, mTessControlShader, mTessEvalShader;
	ShaderProgram mTessProgram;

	DoomBoxCollider3DC* mBoxCollider;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
	MeshC* GetMeshComponent() { return mMeshComponent; };
};

