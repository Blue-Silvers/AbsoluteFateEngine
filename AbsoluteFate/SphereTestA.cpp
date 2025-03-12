#include "SphereTestA.h"

#include "Asset.h"
#include <iostream>

#include "Log.h"

void SphereTestA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/meme.png", "yes");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/pokeball.png", "Pokeball");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Loader_car_Material_Base_Color.png", "forklift");
	Asset::LoadMesh("Resources/3D_Models/sphere.obj", "sphere");
	Asset::LoadMesh("Resources/3D_Models/Loader_car.obj", "Forklift");
	//Actor
	SetScale(Vector3{ 1, 1, 1 }); //scale
	SetPosition(Vector3{ 0, 4, 0 }); //location

	mMeshComponent = new MeshC(this, &Asset::GetMesh("sphere"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("Pokeball")});

	AddComponent(mMeshComponent);
}

void SphereTestA::Update()
{
	//mTransform.RotateXInDegrees(1);
	mTransform.RotateZInDegrees(1);
}

void SphereTestA::Destroy()
{
}
