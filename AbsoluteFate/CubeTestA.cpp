#include "CubeTestA.h"

#include "MeshC.h"
#include "Asset.h"
#include <iostream>

void CubeTestA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/meme.png", "yes");
	Asset::LoadMesh("Resources/3D_Models/cube.obj", "cube");
	//Actor
	SetScale(Vector3{ 1, 1, 1 }); //scale
	SetPosition(Vector3{ 0, 0, 0 }); //location
	//mesh component
	mMeshComponent = new MeshC(this, &Asset::GetMesh("cube"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("yes")});
	AddComponent(mMeshComponent);

	//change shader
	Shader newVertexShader;
	newVertexShader.Load("TransformVert.shader", ShaderType::VERTEX);
	mMeshComponent->GetMesh()->SetVertexShader(newVertexShader);
	mMeshComponent->SetTiling({ 4,4 });
	mMeshComponent->SetOffset({ 0.5,0.5 });
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