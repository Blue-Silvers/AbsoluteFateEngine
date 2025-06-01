#include "DoomGunA.h"
#include "Asset.h"

void DoomGunA::Start()
{
	Asset::LoadAllTextureFromFolder(*mSceneAttached->GetRenderer(), "Resources/Anim/DoomGun/Idle", "DoomIdle");
	Asset::LoadAllTextureFromFolder(*mSceneAttached->GetRenderer(), "Resources/Anim/DoomGun/Walk", "DoomWalk");
	Asset::LoadAllTextureFromFolder(*mSceneAttached->GetRenderer(), "Resources/Anim/DoomGun/Shoot", "DoomShoot");
	//Actor
	SetScale2D(Vector2{ 3, 3 }); //scale
	SetPosition2D(Vector2{ 10, -250 }); //location
	//anim component
	mGun = new AnimatedSpriteC(this, Asset::GetAnimation("DoomIdle"));
	mGun->SetAnimationFps(1);
	AddComponent(mGun);
}

void DoomGunA::Update()
{
}

void DoomGunA::Destroy()
{
}