#include "BowlingPathA.h"

#include "Asset.h"
#include <iostream>

void BowlingPathA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/meme.png", "BowlingPath");
	Asset::LoadMesh("Resources/3D_Models/cube.obj", "cube");
	//Actor
	SetScale(Vector3{ 50, 7, 1 }); //scale
	SetPosition(Vector3{ 15, 0, -2 }); //location
	//mesh component
	mMeshComponent = new MeshC(this, &Asset::GetMesh("cube"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("BowlingPath")});
	AddComponent(mMeshComponent);
}

void BowlingPathA::Update()
{

}

void BowlingPathA::Destroy()
{
	delete mMeshComponent;
}
