#include "SphereTestA.h"

#include "MeshC.h"
#include "Asset.h"
#include <iostream>

void SphereTestA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/meme.png", "yes");
	mMesh = Asset::LoadMeshFromFile("Resources/3D_Models/sphere.obj");
	//Actor
	SetScale(Vector3{ 1, 1, 1 }); //scale
	SetPosition(Vector3{ 0, 4, 0 }); //location
	//sprite component
	//mMeshComponent = new MeshC(this);
	mMeshComponent = new MeshC(this, &mMesh);
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
