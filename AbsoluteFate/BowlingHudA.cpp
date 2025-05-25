#include "BowlingHudA.h"

#include "SpriteC.h"
#include "Asset.h"
#include <iostream>

void BowlingHudA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/arrow.png", "arrow");

	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/pokeball.png", "Skin1");
	Asset::LoadMesh("Resources/3D_Models/sphere.obj", "sphereSkin1");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/meme.png", "Skin2");
	Asset::LoadMesh("Resources/3D_Models/sphere.obj", "sphereSkin2");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Alive.png", "Skin3");
	Asset::LoadMesh("Resources/3D_Models/sphere.obj", "sphereSkin3");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/theBlock.png", "Skin4");
	Asset::LoadMesh("Resources/3D_Models/sphere.obj", "sphereSkin4");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Fea.png", "Skin5");
	Asset::LoadMesh("Resources/3D_Models/sphere.obj", "sphereSkin5");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Wait.png", "Skin6");
	Asset::LoadMesh("Resources/3D_Models/sphere.obj", "sphereSkin6");

	//Actor
	SetScale2D(Vector2{ 0.2F, 0.2F }); //scale
	SetPosition2D(Vector2{ 0, -300 }); //location
	//sprite component
	SpriteC* mSprite = new SpriteC(this, Asset::GetTexture("arrow"));
	AddComponent(mSprite);

	//Skin
	mSkinList.push_back(new SphereTestA());
	mSkinList.push_back(new SphereTestA());
	mSkinList.push_back(new SphereTestA());
	mSkinList.push_back(new SphereTestA());
	mSkinList.push_back(new SphereTestA());
	mSkinList.push_back(new SphereTestA());
	for (Actor* actor : mSkinList)
	{
		actor->AttachScene(GetScene());
		actor->Start();
	}

	mSkinList[0]->SetPosition(Vector3(30, -15, 12));
	mSkinList[1]->SetPosition(Vector3(30, -9, 12));
	mSkinList[2]->SetPosition(Vector3(30, -3, 12));
	mSkinList[3]->SetPosition(Vector3(30, 3, 12));
	mSkinList[4]->SetPosition(Vector3(30, 9, 12));
	mSkinList[5]->SetPosition(Vector3(30, 15, 12));

	mSkinList[0]->GetMeshC()->SetMesh(Asset::GetMesh("sphereSkin1"));
	mSkinList[1]->GetMeshC()->SetMesh(Asset::GetMesh("sphereSkin2"));
	mSkinList[2]->GetMeshC()->SetMesh(Asset::GetMesh("sphereSkin3"));
	mSkinList[3]->GetMeshC()->SetMesh(Asset::GetMesh("sphereSkin4"));
	mSkinList[4]->GetMeshC()->SetMesh(Asset::GetMesh("sphereSkin5"));
	mSkinList[5]->GetMeshC()->SetMesh(Asset::GetMesh("sphereSkin6"));

	mSkinList[0]->GetMeshC()->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("Skin1")});
	mSkinList[1]->GetMeshC()->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("Skin2")});
	mSkinList[2]->GetMeshC()->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("Skin3")});
	mSkinList[3]->GetMeshC()->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("Skin4")});
	mSkinList[4]->GetMeshC()->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("Skin5")});
	mSkinList[5]->GetMeshC()->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("Skin6")});
}

void BowlingHudA::Update()
{
	for (Actor* actor : mSkinList)
	{
		actor->Update();
	}
}

void BowlingHudA::Destroy()
{
	GetAllComponent().clear();
	mSkinList.clear();
}
