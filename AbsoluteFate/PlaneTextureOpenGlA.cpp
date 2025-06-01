#include "PlaneTextureOpenGlA.h"

#include "SpriteC.h"
#include "AnimatedSpriteC.h"
#include "Asset.h"
#include <iostream>

void PlaneTextureOpenGlA::Start()
{
	//load texture
	Asset::LoadAllTextureFromFolder(*mSceneAttached->GetRenderer(), "Resources/Anim/DeathAngel/Idle/FrontIdle", "FrontIdle");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/meme.png", "yes");
	//Actor
	SetScale2D(Vector2{ 1, 1 }); //scale
	SetPosition2D(Vector2{ -300, 300 }); //location
	//anim component
	AnimatedSpriteC* animation = new AnimatedSpriteC(this, Asset::GetAnimation("FrontIdle"));
	animation->SetAnimationFps(2);
	AddComponent(animation);
}

void PlaneTextureOpenGlA::Update()
{
}

void PlaneTextureOpenGlA::Destroy()
{
}