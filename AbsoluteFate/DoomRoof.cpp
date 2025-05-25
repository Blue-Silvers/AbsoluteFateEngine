#include "DoomRoof.h"

#include "Asset.h"
#include <iostream>

void DoomRoof::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Doom/116.png", "DtextRoof");
	Asset::LoadMesh("Resources/3D_Models/cube.obj", "doomRoof");
	//Actor
	SetScale(Vector3{ 50, 50, 0.1F }); //scale
	SetPosition(Vector3{ 10, 0, 7 }); //location
	//mesh component
	mMeshComponent = new MeshC(this, &Asset::GetMesh("doomRoof"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("DtextRoof")});
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

void DoomRoof::Update()
{
}

void DoomRoof::Destroy()
{
}
