#include "DoomWall.h"

#include "Asset.h"
#include <iostream>

void DoomWall::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Doom/122.png", "DtextWall");
	Asset::LoadMesh("Resources/3D_Models/cube.obj", "doomWall");

	//mesh component
	mMeshComponent = new MeshC(this, &Asset::GetMesh("doomWall"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("DtextWall")});
	AddComponent(mMeshComponent);

	//box collider
	mBoxCollider = new DoomBoxCollider3DC(this);
	mBoxCollider->SetCustomSize(Vector3(1, 1, 1));
	AddComponent(mBoxCollider);

	//change shader
	mTessVertexShader.Load("TessSimpleVert.shader", ShaderType::VERTEX);
	mTessFragShader.Load("TessSimpleFrag.shader", ShaderType::FRAGMENT);
	mTessControlShader.Load("TessSimpleTesc.shader", ShaderType::TESSELLATION_CONTROL);
	mTessEvalShader.Load("TessSimpleTese.shader", ShaderType::TESSELLATION_EVALUATION);

	mTessProgram.Compose({ &mTessVertexShader, &mTessFragShader, &mTessControlShader, &mTessEvalShader });
	mMeshComponent->GetMesh()->SetShaderProgram(mTessProgram);
	mMeshComponent->EnableTesselation();
	mMeshComponent->SetTesselationLevel(10);

	mMeshComponent->SetTiling({ 50,5 });
}

void DoomWall::Update()
{
}

void DoomWall::Destroy()
{
}
