#include "ComputeShaderScene.h"
#include <iostream>
#include <cmath>
#include "RendererGl.h"
#include "Time.h"

#include "Log.h"

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

    // Coulor
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Particle), (void*)offsetof(Particle, color));

    glBindVertexArray(0);

    Scene::Start();
}

void ComputeShaderScene::Update()
{
	Scene::Update();
    mTotalTime += SDL_GetTicks() / 10000.0f;
}

//Drawing
void ComputeShaderScene::Render()
{
    glEnable(GL_PROGRAM_POINT_SIZE);

        if (mComputeShader)
        {
            mComputeShader->Bind();

            mComputeShader->setFloat("uDeltaTime", Time::deltaTime);
            mComputeShader->setFloat("uTime", mTotalTime);

            ///DEBUG///
            //Log::Info(to_string(mTotalTime));

            int windowWidth, windowHeight;
            SDL_GetWindowSize(SDL_GL_GetCurrentWindow(), &windowWidth, &windowHeight);
            int mouseX = 0;
            int mouseY = 0;
            SDL_GetMouseState(&mouseX, &mouseY);
            // CONVERSION CRITIQUE
            float ndcX = (2.0f * mouseX) / (float)windowWidth - 1.0f;
            float ndcY = 1.0f - (2.0f * mouseY) / (float)windowHeight;
            Vector2 mousePos = { (float)ndcX , (float)ndcY };

            mComputeShader->setVector2f("uMousePos", mousePos);

            glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, mSSBO);

            mComputeShader->Dispatch(mParticleCount / 256, 1, 1);

            glMemoryBarrier(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT);

            mComputeShader->Unbind();
        }

        if (RendererGl* renderer = dynamic_cast<RendererGl*>(mRenderer))
        {
            mShaderProgram->Use();

            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE);
            glEnable(GL_PROGRAM_POINT_SIZE);

            glBindVertexArray(mVAO);

            glDrawArrays(GL_POINTS, 0, mParticleCount);

            glBindVertexArray(0);
            glDisable(GL_BLEND);
        }

        Scene::Render();
}

void ComputeShaderScene::Close()
{
    delete mComputeShader;
    Scene::Close();
}