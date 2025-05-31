#include "BeachA.h"

#include "Asset.h"
#include <iostream>
#include "Shader.h"

void BeachA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Sand_Beach_Base_Basecolor.png", "Sand");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Noise/SandNoise.jpg", "SandNoise");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Normal/Sand_Beach_Base_Normal.png", "SandBeachBaseNormal");
	Asset::LoadMesh("Resources/3D_Models/cube.obj", "Beach");
	//Actor
	SetScale(Vector3{ 50, 50, 0.02F }); //scale
	SetPosition(Vector3{ 50, 99, -11}); //location
	//mesh component
	mMeshComponent = new MeshC(this, &Asset::GetMesh("Beach"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("Sand")});
	mMeshComponent->GetMesh()->SetNoiseTexture(&Asset::GetTexture("SandNoise"));
	mMeshComponent->GetMesh()->SetNormalTexture(&Asset::GetTexture("SandBeachBaseNormal"));
	AddComponent(mMeshComponent);

	//change shader

	mTessVertexShader.Load("TessNoiseNormalVert.shader", ShaderType::VERTEX);
	mTessFragShader.Load("TessNoiseNormalFrag.shader", ShaderType::FRAGMENT);
	mTessControlShader.Load("TessNoiseNormalTesc.shader", ShaderType::TESSELLATION_CONTROL);
	mTessEvalShader.Load("TessNoiseNormalTese.shader", ShaderType::TESSELLATION_EVALUATION);

	mTessProgram.Compose({ &mTessVertexShader, &mTessFragShader, &mTessControlShader, &mTessEvalShader });
	mMeshComponent->GetMesh()->SetShaderProgram(mTessProgram);
	mMeshComponent->EnableTesselation();
	mMeshComponent->SetTesselationLevel(20);

	mMeshComponent->AutoTile();

	//Update shader uniform
	mMeshComponent->GetMesh()->GetShaderProgram().setFloat("uHeightFactor", mHeightFactor);
	mMeshComponent->GetMesh()->GetShaderProgram().setFloat("uShadowFactor", mShadowFactor);
	mMeshComponent->GetMesh()->GetShaderProgram().setVector3f("uLightDir", 80, 20, 20);
	mMeshComponent->GetMesh()->GetShaderProgram().setVector2f("uNormalTiling", 0.5, 0.5);
	mMeshComponent->GetMesh()->GetShaderProgram().setFloat("uNormalStrength", 0.2);
}

void BeachA::Update()
{
}

void BeachA::Destroy()
{
}