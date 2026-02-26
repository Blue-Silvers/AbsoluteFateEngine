#pragma once
#include "Actor.h"
#include "MeshC.h"

class FluidPlaneA : public Actor
{
private:
	MeshC* mMeshComponent;
    /**/
    Shader mTessVertexShader, mTessFragShader, mTessControlShader, mTessEvalShader;
    ShaderProgram mTessProgram;/**/

    // Shaders
    Shader mVertexShader, mAdvectShader, mDivergenceShader, mPressureShader, mProjectionShader, mAddForceShader;

    ShaderProgram mAdvectProgram, mDivergenceProgram, mPressureProgram, mProjectionProgram, mAddForceProgram;

    VertexArray mQuad;

    // Textures
    GLuint velocityTex[2] = { 0,0 };
    GLuint densityTex[2] = { 0,0 };
    GLuint pressureTex[2] = { 0,0 };
    GLuint divergenceTex = 0;
    int pingpongIndex = 0;

    // Simulation
    int simWidth = 800;
    int simHeight = 800;
    float timeStep = 0.1f;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
};