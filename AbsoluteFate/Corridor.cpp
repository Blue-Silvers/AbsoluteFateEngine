#include "Corridor.h"

#include "MeshC.h"
#include "Asset.h"
#include <iostream>
#include "Shader.h"

void Corridor::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Plank2.png", "Plank2");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Plank.png", "Plank1");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Plank3.png", "Plank3");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/TerrainNoise.png", "TerrainNoise");

	Asset::LoadMesh("Resources/3D_Models/cube.obj", "corridor");
	//Actor
	SetScale(Vector3{ 50, 50, 0.1F }); //scale
	SetPosition(Vector3{ 50, 0, -10 }); //location

	//Mesh component
	mMeshComponent = new MeshC(this, &Asset::GetMesh("corridor"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("Plank2"), &Asset::GetTexture("Plank1"), &Asset::GetTexture("Plank2"), &Asset::GetTexture("Plank3")});
	mMeshComponent->GetMesh()->SetNoiseTexture(&Asset::GetTexture("TerrainNoise"));
	AddComponent(mMeshComponent);

	//change shader
	mTessVertexShader.Load("TessSimpleVert.shader", ShaderType::VERTEX);
	mTessFragShader.Load("TessSimpleFrag.shader", ShaderType::FRAGMENT);
	mTessControlShader.Load("TessSimpleTesc.shader", ShaderType::TESSELLATION_CONTROL);
	mTessEvalShader.Load("TessSimpleTese.shader", ShaderType::TESSELLATION_EVALUATION);

	mTessProgram.Compose({ &mTessVertexShader, &mTessFragShader, &mTessControlShader, &mTessEvalShader });
	mMeshComponent->GetMesh()->SetShaderProgram(mTessProgram);
	mMeshComponent->EnableTesselation();
	mMeshComponent->SetTesselationLevel(20);

	mMeshComponent->AutoTile();
}

void Corridor::Update()
{
}

void Corridor::Destroy()
{
}