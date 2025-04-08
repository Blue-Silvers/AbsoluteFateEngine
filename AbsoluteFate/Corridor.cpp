#include "Corridor.h"

#include "MeshC.h"
#include "Asset.h"
#include <iostream>
#include "Shader.h"

void Corridor::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Plank2.png", "Plank2");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Plank.png", "Plank1");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Plank3.png", "Plank3");
	Asset::LoadMesh("Resources/3D_Models/cube.obj", "corridor");
	//Actor
	SetScale(Vector3{ 100, 50, 1 }); //scale
	SetPosition(Vector3{ 50, 0, -10 }); //location
	//mesh component
	mMeshComponent = new MeshC(this, &Asset::GetMesh("corridor"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("Plank2"), &Asset::GetTexture("Plank1"), &Asset::GetTexture("Plank2"), &Asset::GetTexture("Plank3")});
	AddComponent(mMeshComponent);

	//change shader
	Shader newVertexShader;
	newVertexShader.Load("TransformVert.shader", ShaderType::VERTEX);
	mMeshComponent->GetMesh()->SetVertexShader(newVertexShader);
	mMeshComponent->AutoTile();
}

void Corridor::Update()
{
}

void Corridor::Destroy()
{
}
