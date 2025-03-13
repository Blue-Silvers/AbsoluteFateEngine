#include "SphereTestA.h"

#include "Asset.h"
#include <iostream>

#include "Log.h"

void SphereTestA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/pokeball.png", "Pokeball");
	Asset::LoadMesh("Resources/3D_Models/sphere.obj", "sphere");
	//Actor
	SetScale(Vector3{ 1, 1, 1 }); //scale
	SetPosition(Vector3{ 0, 0, 0 }); //location

	mMeshComponent = new MeshC(this, &Asset::GetMesh("sphere"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("Pokeball")});

	AddComponent(mMeshComponent);

	mBoxCollider = new BoxCollider3DC(this);
	mBoxCollider->SetCustomSize(Vector3(2, 2, 2));
	AddComponent(mBoxCollider);

	AddTag("bowlingPin");
}

void SphereTestA::Update()
{
	//Log::Info("" + std::to_string(GetTransform().GetPosition().x) + ", " + std::to_string(GetTransform().GetPosition().y) + ", " + std::to_string(GetTransform().GetPosition().z));


	//mTransform.RotateXInDegrees(1);
	mTransform.RotateZInDegrees(5);

	/*if (mBoxCollider->OnCollide() == true)
	{
		//Log::Info("" + std::to_string(mTransform.GetRotation().x) + ", " + std::to_string(mTransform.GetRotation().y) + ", " + std::to_string(mTransform.GetRotation().z));
	}*/
}

void SphereTestA::Destroy()
{
}
