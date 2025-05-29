#include "WaveA.h"

#include "MeshC.h"
#include "Asset.h"
#include <iostream>
#include "Shader.h"

void WaveA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/White.png", "White");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Noise/PerlinNoise.png", "PerlinNoise");
	Asset::LoadMesh("Resources/3D_Models/cube.obj", "wave");
	//Actor
	SetScale(Vector3{ 50, 50, 0.02F }); //scale
	SetPosition(Vector3{ 50, 0, -10 }); //location
	//mesh component
	mMeshComponent = new MeshC(this, &Asset::GetMesh("wave"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("White")});
	mMeshComponent->GetMesh()->SetNoiseTexture(&Asset::GetTexture("PerlinNoise"));
	AddComponent(mMeshComponent);

	//change shader

	mTessVertexShader.Load("TessWaveVert.shader", ShaderType::VERTEX);
	mTessFragShader.Load("TessWaveFrag.shader", ShaderType::FRAGMENT);
	mTessControlShader.Load("TessWaveTesc.shader", ShaderType::TESSELLATION_CONTROL);
	mTessEvalShader.Load("TessWaveTese.shader", ShaderType::TESSELLATION_EVALUATION);

	mTessProgram.Compose({ &mTessVertexShader, &mTessFragShader, &mTessControlShader, &mTessEvalShader });
	mMeshComponent->GetMesh()->SetShaderProgram(mTessProgram);
	mMeshComponent->EnableTesselation();
	mMeshComponent->SetTesselationLevel(20);

	mMeshComponent->AutoTile();

}

void WaveA::Update()
{
	/*panicFloat += 0.01;
	mMeshComponent->SetTesselationLevel((int)panicFloat);*/
}

void WaveA::Destroy()
{
}