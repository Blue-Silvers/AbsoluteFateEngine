#include "FluidScene.h"
#include <iostream>
#include <cmath>
#include "RendererGl.h"

void FluidScene::SetRenderer(IRenderer* pRenderer)
{
    mRenderer = pRenderer;
}

void FluidScene::Start()
{
    // Load shaders
    mVertexShader.Load("FluidFullscreenVert.shader", ShaderType::VERTEX);
    mAdvectShader.Load("FluidAdvectFrag.shader", ShaderType::FRAGMENT);
    mDivergenceShader.Load("FluidDivergenceFrag.shader", ShaderType::FRAGMENT);
    mPressureShader.Load("FluidPressureFrag.shader", ShaderType::FRAGMENT);
    mProjectionShader.Load("FluidProjectionFrag.shader", ShaderType::FRAGMENT);
    mAddForceShader.Load("FluidAddForceFrag.shader", ShaderType::FRAGMENT);

    // Compose programs
    mAdvectProgram = new ShaderProgram(); mAdvectProgram->Compose({ &mVertexShader, &mAdvectShader });
    mDivergenceProgram = new ShaderProgram(); mDivergenceProgram->Compose({ &mVertexShader, &mDivergenceShader });
    mPressureProgram = new ShaderProgram(); mPressureProgram->Compose({ &mVertexShader, &mPressureShader });
    mProjectionProgram = new ShaderProgram(); mProjectionProgram->Compose({ &mVertexShader, &mProjectionShader });
    mAddForceProgram = new ShaderProgram(); mAddForceProgram->Compose({ &mVertexShader, &mAddForceShader });


    if (RendererGl* renderer = dynamic_cast<RendererGl*>(mRenderer))
    {
        renderer->SetShaderProgram(mAdvectProgram);
    }
    // Fullscreen quad
    //mQuad = VertexArray(spriteVertices, 4, indices, 6);

    //// Framebuffer
    //glGenFramebuffers(1, &fbo);

    //// Create textures
    //CreateTextures();

    //// Add initial density/velocity
    //AddInitialForce();


    //Sprite shader
    mShaderProgram = new ShaderProgram();

    mTestVertexShader.Load("TransformVert.shader", ShaderType::VERTEX);
    mFragmentShader.Load("SpriteFrag.shader", ShaderType::FRAGMENT);

    mShaderProgram->Compose({ &mTestVertexShader , &mFragmentShader });

    if (RendererGl* renderer = dynamic_cast<RendererGl*>(mRenderer))
    {
        renderer->SetShaderProgram(mShaderProgram);
    }
    //Actors
    cam = new CameraA();
    cam->AttachScene(this);
    AddActor(cam);

    mFluidPlane = new FluidPlaneA();
    mFluidPlane->AttachScene(this);
    AddActor(mFluidPlane);

    /*corridor = new Corridor();
    corridor->AttachScene(this);
    AddActor(corridor);*/

    Scene::Start();
    cam->SetPosition(Vector3{ -1.5, 0, 0 });
}

void FluidScene::CreateTextures()
{
    /*glGenTextures(2, velocityTex);
    glGenTextures(2, densityTex);
    glGenTextures(2, pressureTex);
    glGenTextures(1, &divergenceTex);

    auto initTex = [this](GLuint tex) {
        glBindTexture(GL_TEXTURE_2D, tex);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, simWidth, simHeight, 0, GL_RGBA, GL_FLOAT, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        };

    for (int i = 0; i < 2; ++i) {
        initTex(velocityTex[i]);
        initTex(densityTex[i]);
        initTex(pressureTex[i]);
    }
    initTex(divergenceTex);*/
}

void FluidScene::AddInitialForce()
{
    /*glBindFramebuffer(GL_FRAMEBUFFER, fbo);
    glViewport(0, 0, simWidth, simHeight);

    // Bind velocityTex[0] as render target
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, velocityTex[0], 0);
    glClearColor(0, 0, 0, 0); glClear(GL_COLOR_BUFFER_BIT);

    // Bind densityTex[0] as render target
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, densityTex[0], 0);
    glClearColor(0, 0, 0, 0); glClear(GL_COLOR_BUFFER_BIT);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);*/
}

void FluidScene::SwapPingPong() { pingpongIndex = 1 - pingpongIndex; }

void FluidScene::DispatchShader(ShaderProgram* program, GLuint inputTex, GLuint extraTex, float delta)
{
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);

    GLuint outputTex = inputTex;
    if (program == mAdvectProgram) outputTex = densityTex[1 - pingpongIndex];
    else if (program == mDivergenceProgram) outputTex = divergenceTex;
    else if (program == mPressureProgram) outputTex = pressureTex[1 - pingpongIndex];
    else if (program == mProjectionProgram) outputTex = velocityTex[1 - pingpongIndex];
    else if (program == mAddForceProgram) outputTex = velocityTex[1 - pingpongIndex];

    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, outputTex, 0);
    glViewport(0, 0, simWidth, simHeight);
    glClear(GL_COLOR_BUFFER_BIT);

    program->Use();
    program->setFloat("uTimeStep", timeStep);
    program->setFloat("uDelta", delta);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, inputTex);
    program->setInteger("uInputTex", 0);

    if (extraTex != 0) {
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, extraTex);
        program->setInteger("uExtraTex", 1);
    }

    mQuad.SetActive();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void FluidScene::Update()
{
    Scene::Update();
    /*
    // Advect velocity
    DispatchShader(mAdvectProgram, velocityTex[pingpongIndex], velocityTex[pingpongIndex]);
    SwapPingPong();

    // Compute divergence
    DispatchShader(mDivergenceProgram, velocityTex[pingpongIndex]);

    // Solve pressure (Jacobi iterations)
    for (int i = 0; i < 20; ++i) {
        DispatchShader(mPressureProgram, pressureTex[pingpongIndex], divergenceTex);
        SwapPingPong();
    }

    // Subtract gradient
    DispatchShader(mProjectionProgram, velocityTex[pingpongIndex], pressureTex[pingpongIndex]);
    SwapPingPong();

    // Advect density
    DispatchShader(mAdvectProgram, densityTex[pingpongIndex], velocityTex[pingpongIndex]);
    SwapPingPong();

    // Add external forces (example)
    DispatchShader(mAddForceProgram, velocityTex[pingpongIndex]);
    SwapPingPong();*/
}

void FluidScene::Render()
{
    Scene::Render();
    //glViewport(0, 0, 800, 800);
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //// Render density
    //mAdvectProgram->Use();
    //glActiveTexture(GL_TEXTURE0);
    //glBindTexture(GL_TEXTURE_2D, densityTex[pingpongIndex]);
    //mAdvectProgram->setInteger("uInputTex", 0);

    //mQuad.SetActive();
    //glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

}

void FluidScene::Close()
{
    
}