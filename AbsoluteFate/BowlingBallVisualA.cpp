#include "BowlingBallVisualA.h"

#include "Asset.h"
#include <iostream>

#include "Log.h"

void BowlingBallVisualA::Start()
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

}

void BowlingBallVisualA::Update()
{
}

void BowlingBallVisualA::Destroy()
{
	delete mMeshComponent;
}