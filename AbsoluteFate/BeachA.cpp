#include "BeachA.h"

#include "Asset.h"
#include <iostream>
#include "Shader.h"

void BeachA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Sand_Beach_Base_Basecolor.png", "Sand");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Noise/Sand_Beach_Noise.png", "SandNoise");
	Asset::LoadMesh("Resources/3D_Models/plane.obj", "Beach");
	//Actor
	SetScale(Vector3{ 50, 50, 1 }); //scale
	SetPosition(Vector3{ 50, 100, -10 }); //location
	//mesh component
	mMeshComponent = new MeshC(this, &Asset::GetMesh("Beach"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("Sand")});
	mMeshComponent->GetMesh()->SetNoiseTexture(&Asset::GetTexture("SandNoise"));
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

	//Update shader uniform
	mMeshComponent->GetMesh()->GetShaderProgram().setFloat("uDisplacement", mDisplacement);
}

void BeachA::Update()
{
}

void BeachA::Destroy()
{
}