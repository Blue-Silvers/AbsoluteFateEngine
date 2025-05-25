#include "DoomFloor.h"

#include "Asset.h"
#include <iostream>

void DoomFloor::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Plank2.png", "Plank2");
	Asset::LoadMesh("Resources/3D_Models/cube.obj", "doomFloor");
	//Actor
	SetScale(Vector3{ 50, 50, 0.1F }); //scale
	SetPosition(Vector3{ 10, 0, -3 }); //location
	//mesh component
	mMeshComponent = new MeshC(this, &Asset::GetMesh("doomFloor"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("Plank2")});
	AddComponent(mMeshComponent);

	//change shader
	mTessVertexShader.Load("TessSimpleVert.shader", ShaderType::VERTEX);
	mTessFragShader.Load("TessSimpleFrag.shader", ShaderType::FRAGMENT);
	mTessControlShader.Load("TessSimpleTesc.shader", ShaderType::TESSELLATION_CONTROL);
	mTessEvalShader.Load("TessSimpleTese.shader", ShaderType::TESSELLATION_EVALUATION);

	mTessProgram.Compose({ &mTessVertexShader, &mTessFragShader, &mTessControlShader, &mTessEvalShader });
	mMeshComponent->GetMesh()->SetShaderProgram(mTessProgram);
	mMeshComponent->EnableTesselation();
	mMeshComponent->SetTesselationLevel(10);

	mMeshComponent->AutoTile();
}

void DoomFloor::Update()
{
}

void DoomFloor::Destroy()
{
}
