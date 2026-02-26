#pragma once
#include "Scene.h"
#include "ShaderProgram.h"
#include "Shader.h"
#include "VertexArray.h"
#include "FluidPlaneA.h"
#include "CameraA.h"
#include "Corridor.h"


class FluidScene : public Scene
{
private:
    Shader mTestVertexShader;
    Shader mFragmentShader;
    ShaderProgram* mShaderProgram;
    VertexArray mVertexArray;
    //actor
    CameraA* cam;
    FluidPlaneA* mFluidPlane;
    Corridor* corridor;



    // Shaders
    Shader mVertexShader;
    Shader mAdvectShader;
    Shader mDivergenceShader;
    Shader mPressureShader;
    Shader mProjectionShader;
    Shader mAddForceShader;

    ShaderProgram* mAdvectProgram;
    ShaderProgram* mDivergenceProgram;
    ShaderProgram* mPressureProgram;
    ShaderProgram* mProjectionProgram;
    ShaderProgram* mAddForceProgram;

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

    GLuint fbo = 0;

public:
    void SetRenderer(IRenderer* pRenderer) override;
    void Start() override;
    void Update() override;
    void Render() override;
    void Close() override;

private:
    void CreateTextures();
    void SwapPingPong();
    void DispatchShader(ShaderProgram* program, GLuint inputTex, GLuint extraTex = 0, float delta = 0.0f);
    void AddInitialForce();
};