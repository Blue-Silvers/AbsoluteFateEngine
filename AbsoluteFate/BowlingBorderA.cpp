#include "BowlingBorderA.h"

#include "Asset.h"
#include <iostream>

void BowlingBorderA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/pokeball.png", "BowlingBorder");
	Asset::LoadMesh("Resources/3D_Models/cube.obj", "cubeBorder");
	//Actor
	SetScale(Vector3{ 50, 0.5, 2 }); //scale
	SetPosition(Vector3{ 15, 10, -2 }); //location
	//mesh component
	mMeshComponent = new MeshC(this, &Asset::GetMesh("cubeBorder"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("BowlingBorder")});
	AddComponent(mMeshComponent);

	mBoxCollider = new BoxCollider3DC(this);
	mBoxCollider->SetCustomSize(Vector3(1, 3, 2));
	AddComponent(mBoxCollider);
}

void BowlingBorderA::Update()
{
}

void BowlingBorderA::Destroy()
{
}
