#pragma once
#include "Actor.h"
#include "MeshC.h"

class WaveA : public Actor
{
private:
	MeshC* mMeshComponent;
	Shader mTessVertexShader, mTessFragShader, mTessControlShader, mTessEvalShader;
	ShaderProgram mTessProgram;

	float mDisplacement = 25;
	float mAmplitude = 0.09;
	float mFrequency = 1.5;
	float mSpeed = 1;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
};

