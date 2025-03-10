#include "SphereTestA.h"

#include "MeshC.h"
#include "Asset.h"
#include <iostream>

void SphereTestA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/meme.png", "yes");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/pokeball.png", "Pokeball");
	Asset::LoadMesh("Resources/3D_Models/sphere.obj", "sphere");
	//Actor
	SetScale(Vector3{ 1, 1, 1 }); //scale
	SetPosition(Vector3{ 0, 4, 0 }); //location

	//mMeshComponent = new MeshC(this);

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
