#include "OpenGlPictureA.h"

#include "SpriteC.h"
#include "Asset.h"
#include <iostream>
void OpenGlPictureA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/White.png", "White");
	//Actor
	SetScale2D(Vector2{ 1, 1 }); //scale
	SetPosition2D(Vector2{ -300, 300 }); //location
	//sprite component
	SpriteC* sprite = new SpriteC(this, Asset::GetTexture("White"));
	AddComponent(sprite);
}

void OpenGlPictureA::Update()
{
}

void OpenGlPictureA::Destroy()
{
	GetAllComponent().clear();
}
