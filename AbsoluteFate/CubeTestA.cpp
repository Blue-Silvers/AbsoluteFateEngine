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
	MeshC* meshComponent = new MeshC(this);
	Mesh mesh;
	mesh.AddTexture(&Asset::GetTexture("yes"));
	meshComponent->SetMesh(mesh);
	AddComponent(meshComponent);
}

void CubeTestA::Update()
{
	GetTransform().RotateXInDegrees(GetTransform().GetRotationInDegrees().x + 1);
	GetTransform().RotateYInDegrees(GetTransform().GetRotationInDegrees().y + 1);
	GetTransform().RotateZInDegrees(GetTransform().GetRotationInDegrees().z +1);
}

void CubeTestA::Destroy()
{
}