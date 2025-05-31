#include "SecondWaveA.h"

#include "Asset.h"
#include <iostream>
#include "Shader.h"

void SecondWaveA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/White.png", "White");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Noise/PerlinNoise.png", "PerlinNoise");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Normal/Water_Normal.png", "WaterNormal");
	Asset::LoadMesh("Resources/3D_Models/plane.obj", "wave2");
	//Actor
	SetScale(Vector3{ 50, 50, 1 }); //scale
	SetPosition(Vector3{ 50, -100, -10 }); //location
	//mesh component
	mMeshComponent = new MeshC(this, &Asset::GetMesh("wave2"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("White")});
	mMeshComponent->GetMesh()->SetNoiseTexture(&Asset::GetTexture("PerlinNoise"));
	mMeshComponent->GetMesh()->SetNormalTexture(&Asset::GetTexture("WaterNormal"));
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
	mMeshComponent->GetMesh()->GetShaderProgram().setFloat("uAmplitude", mAmplitude);
	mMeshComponent->GetMesh()->GetShaderProgram().setFloat("uFrequency", mFrequency);
	mMeshComponent->GetMesh()->GetShaderProgram().setFloat("uSpeed", mSpeed);
	mMeshComponent->GetMesh()->GetShaderProgram().setBool("uRightClamp", false);
	mMeshComponent->GetMesh()->GetShaderProgram().setVector3f("uLightDir", 80, 20, 20);
	mMeshComponent->GetMesh()->GetShaderProgram().setVector2f("uNormalTiling", 0.5, 0.5);
	mMeshComponent->GetMesh()->GetShaderProgram().setFloat("uNormalStrength", 0.5);
}

void SecondWaveA::Update()
{
}

void SecondWaveA::Destroy()
{
}