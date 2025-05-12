#include "DoomDoor.h"

#include "Asset.h"
#include <iostream>

void DoomDoor::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Doom/168.png", "DtextDoor");
	Asset::LoadMesh("Resources/3D_Models/cube.obj", "doomDoor");

	//actor
	SetScale(Vector3{ 0.99, 4, 4 }); //scale
	SetPosition(Vector3{ -10, 0, 0 }); //location
	//mesh component
	mMeshComponent = new MeshC(this, &Asset::GetMesh("doomDoor"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("DtextDoor")});
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

	mMeshComponent->SetTiling({ 4,4 });

	mDoorOpen = false;
}

void DoomDoor::Update()
{
	if (mDoorOpen == true) 
	{
		OpenDoor();
	}
	else 
	{
		CloseDoor();
	}
}

void DoomDoor::Destroy()
{
}

void DoomDoor::OpenDoor()
{
	if (mTransform.GetPosition().z < 7) 
	{
		SetPosition(mTransform.GetPosition() + Vector3(0, 0, mDoorSpeed));
	}
}

void DoomDoor::CloseDoor()
{
	if (mTransform.GetPosition().z > 0)
	{
		SetPosition(mTransform.GetPosition() - Vector3(0, 0, mDoorSpeed));
	}
}
