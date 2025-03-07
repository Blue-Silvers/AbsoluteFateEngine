#include "CubeTestA.h"

#include "MeshC.h"
#include "Asset.h"
#include <iostream>

void CubeTestA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Ressources/meme.png", "yes");
	//Actor
	SetScale(Vector3{ 1, 1, 1 }); //scale
	SetPosition(Vector3{ 0, 0, 0 }); //location
	//sprite component
	mMeshComponent = new MeshC(this);
	//Mesh mesh = Mesh();
	//mesh.AddTexture(&Asset::GetTexture("yes"));
	//mMeshComponent->SetMesh(mesh);
	AddComponent(mMeshComponent);
}

void CubeTestA::Update()
{
	mTransform.RotateXInDegrees(1);
	mTransform.RotateYInDegrees(1);
	mTransform.RotateZInDegrees(1);
	
}

void CubeTestA::Destroy()
{
}