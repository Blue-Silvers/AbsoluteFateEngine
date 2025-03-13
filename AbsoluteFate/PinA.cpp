#include "PinA.h"

#include "Asset.h"
#include <iostream>

#include "Log.h"

void PinA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/White.png", "Pin_TEX");
	Asset::LoadMesh("Resources/3D_Models/BowlingPin.obj", "pin");
	//Actor
	SetScale(Vector3{ 0.75, 0.75, 0.75 }); //scale
	SetPosition(Vector3{ 0, 0, 0 }); //location
	mTransform.RotateXInDegrees(90);
	mMeshComponent = new MeshC(this, &Asset::GetMesh("pin"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("Pin_TEX")});

	AddComponent(mMeshComponent);

	mBoxCollider = new BoxCollider3DC(this);
	mBoxCollider->SetCustomSize(Vector3(0.1, 2, 0.1));
	AddComponent(mBoxCollider);

	AddTag("bowlingPin");
}

void PinA::Update()
{
	if (mBoxCollider->OnCollide() == true)
	{
		Log::Info("" + std::to_string(mTransform.GetRotation().x) + ", " + std::to_string(mTransform.GetRotation().y) + ", " + std::to_string(mTransform.GetRotation().z));
	}
}

void PinA::Destroy()
{
}
