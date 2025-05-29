#include "NightSkyBoxA.h"

#include "Asset.h"
#include <iostream>

void NightSkyBoxA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Star_skybox.png", "Star_skybox");
	Asset::LoadMesh("Resources/3D_Models/cube.obj", "sky");
	//Actor
	SetScale(Vector3{ 1000, 1000, 1000 }); //scale
	SetPosition(Vector3{ 0, 0, 0 }); //location

	mMeshComponent = new MeshC(this, &Asset::GetMesh("sky"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("Star_skybox")});
	mMeshComponent->SetTiling(Vector2(1000000,100000));
	AddComponent(mMeshComponent);

}

void NightSkyBoxA::Update()
{
	mTransform.RotateZInDegrees(0.1);
}

void NightSkyBoxA::Destroy()
{
}
