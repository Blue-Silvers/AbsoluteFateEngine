#include "CubeScene.h"
#include "Asset.h"
#include "MeshC.h"
#include "SpriteC.h"
#include "Time.h"
#include "RendererGl.h"

CubeScene::CubeScene()
{
}

void CubeScene::Start()
{
    Asset::LoadTexture(*this->GetRenderer(), "Resources/Plank2.png", "yes");

    mVertexShader.Load("TessTest.vert", ShaderType::VERTEX);
    mFragmentShader.Load("TessTest.frag", ShaderType::FRAGMENT);
    mTessControlShader.Load("TessTest.tesc", ShaderType::TESSELLATION_CONTROL);
    mTessEvalShader.Load("TessTest.tese", ShaderType::TESSELLATION_EVALUATION);
    //Asset::CreateShaderProgram({ &mVertexShader, &mFragmentShader, &mTessControlShader, &mTessEvalShader }, "tessTest");
    tessTest.Compose({ &mVertexShader, &mFragmentShader, &mTessControlShader, &mTessEvalShader });
    Actor* cubeActor = new Actor();
    cubeActor->AttachScene(this);
    AddActor(cubeActor);
    cubeActor->SetPosition(Vector3(5, 0, 0));

    Asset::LoadMesh("Resources/3D_Models/cube.obj", "simpleCube");

    MeshC* mc = new MeshC(cubeActor, &Asset::GetMesh("simpleCube"));
   // mc->SetMesh(Asset::GetMesh("simpleCube"));
    mc->GetMesh()->SetShaderProgram(tessTest/*&Asset::GetShader("tessTest")*/);
    mc->EnableTesselation();
    cubeActor->AddComponent(mc);
    //cubeActor->Rotate(Vector3(Maths::ToRad(90), 0, 0));

    /*Actor* ui = new Actor();
    SpriteC* scF = new SpriteC(ui, Asset::GetTexture("lifebar"), 500);
    AddActor(ui);
    ui->SetPosition(Vector3(300.0f, 300.0f, 0.0f));*/
    Scene::Start();

}

void CubeScene::Render()
{
    Scene::Render();
}

void CubeScene::Update()
{
    Scene::Update();
    //mActors[1]->Rotate(Vector3(Maths::ToRad(0) * Time::deltaTime, Maths::ToRad(0) * Time::deltaTime, Maths::ToRad(10) * Time::deltaTime));
}

void CubeScene::Close()
{
}
