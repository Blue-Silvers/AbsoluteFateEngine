#pragma once
#include "Actor.h"
#include "MeshC.h"

class DoomFloor : public Actor
{
private:
	MeshC* mMeshComponent;
	Shader mTessVertexShader, mTessFragShader, mTessControlShader, mTessEvalShader;
	ShaderProgram mTessProgram;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
};