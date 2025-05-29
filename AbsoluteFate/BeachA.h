#pragma once
#include "Actor.h"
#include "MeshC.h"

class BeachA : public Actor
{
private:
	MeshC* mMeshComponent;
	Shader mTessVertexShader, mTessFragShader, mTessControlShader, mTessEvalShader;
	ShaderProgram mTessProgram;
	float panicFloat = 1;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
};

