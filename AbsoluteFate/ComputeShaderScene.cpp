#include "ComputeShaderScene.h"
#include <iostream>
#include <cmath>
#include "RendererGl.h"

void ComputeShaderScene::SetRenderer(IRenderer* pRenderer)
{
	mRenderer = pRenderer;
}

void ComputeShaderScene::Start()
{
    // Init
    mShaderProgram = new ShaderProgram();
    mVertexShader.Load("ParticleVert.shader", ShaderType::VERTEX); 
    mFragmentShader.Load("ParticleFrag.shader", ShaderType::FRAGMENT);
    mShaderProgram->Compose({ &mVertexShader , &mFragmentShader });
    mComputeShader = new ComputeShader("particles.comp");

    // SSBO
    std::vector<Particle> particles(mParticleCount);
    for (auto& p : particles) {
        p.pos = Vector2((rand() % 1000 / 500.0f) - 1.0f, (rand() % 1000 / 500.0f) - 1.0f);
        p.vel = Vector2(0.0f);
        p.color = Vector4(0.2f, 0.6f, 1.0f, 0.8f);
    }

    glGenBuffers(1, &mSSBO);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, mSSBO);
    glBufferData(GL_SHADER_STORAGE_BUFFER, mParticleCount * sizeof(Particle), particles.data(), GL_DYNAMIC_DRAW);

    // VAO
    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);
    glBindBuffer(GL_ARRAY_BUFFER, mSSBO);

    // Position
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Particle), (void*)0);
    // Color
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Particle), (void*)offsetof(Particle, color));

    // Actor setup
    /*cam = new CameraA();
    cam->AttachScene(this);
    AddActor(cam);*/

    Scene::Start();
}

void ComputeShaderScene::Update()
{
	Scene::Update();
}

//Drawing
void ComputeShaderScene::Render()
{
    mComputeShader->Bind();
    mComputeShader->setVector2f("uMousePos", Vector2(0.0f, 0.0f)); // À lier à tes inputs

    // link SSBO 
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, mSSBO);

    // Dispatch
    mComputeShader->Dispatch(mParticleCount / 256, 1, 1);

    // synchronise
    RendererGl::Wait(MemoryBarrier::VertexAttribute);

    mComputeShader->Unbind();

    if (RendererGl* renderer = dynamic_cast<RendererGl*>(mRenderer)) {
        renderer->SetShaderProgram(mShaderProgram);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);

        glBindVertexArray(mVAO);
        glDrawArrays(GL_POINTS, 0, mParticleCount);

        glDisable(GL_BLEND);
    }

    Scene::Render();
}

void ComputeShaderScene::Close()
{
    delete mComputeShader;
    Scene::Close();
}