#include "BowlingHudA.h"

#include "SpriteC.h"
#include "Asset.h"
#include <iostream>

void BowlingHudA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/arrow.png", "arrow");
	//Actor
	SetScale2D(Vector2{ 0.2, 0.2 }); //scale
	SetPosition2D(Vector2{ 0, -300 }); //location
	//sprite component
	SpriteC* mSprite = new SpriteC(this, Asset::GetTexture("arrow"));
	AddComponent(mSprite);
}

void BowlingHudA::Update()
{
}

void BowlingHudA::Destroy()
{
	//RemoveComponent(mSprite);
	//delete mSprite;
}
