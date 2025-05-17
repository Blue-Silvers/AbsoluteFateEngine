#include "DoomLever.h"

#include "Asset.h"
#include <iostream>

void DoomLever::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Doom/402.png", "DLeverOff");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Doom/403.png", "DLeverOn");
	Asset::LoadMesh("Resources/3D_Models/cube.obj", "doomLever");

	//actor
	SetScale(Vector3{ 0.2, 0.8, 0.8 }); //scale
	SetPosition(Vector3{ -39, 0, 0 }); //location
	mTransform.RotateXInDegrees(180);

	//box collider
	mBoxCollider = new DoomBoxCollider3DC(this);
	mBoxCollider->SetCustomSize(Vector3(30, 5, 1));
	mBoxCollider->SetIsOverlap(true);
	AddComponent(mBoxCollider);

	//mesh component
	mMeshComponent = new MeshC(this, &Asset::GetMesh("doomLever"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("DLeverOff")});
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

	mMeshComponent->SetTiling({ 5*0.8,5*0.8 });
	mMeshComponent->SetOffset({ 0.5,0 });

	mLeverActive = false;
}

void DoomLever::Restart()
{
	mLeverActive = false;
}

void DoomLever::Update()
{
	mDoorLinked->SetDoorOpen(mLeverActive);
	if (mLeverActive == true)
	{
		mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("DLeverOn")});
	}
	else 
	{
		mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("DLeverOff")});
	}
}

void DoomLever::Destroy()
{
}
