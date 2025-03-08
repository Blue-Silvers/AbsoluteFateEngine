#include "PlaneTextureOpenGlA.h"

#include "SpriteC.h"
#include "Asset.h"
#include <iostream>

void PlaneTextureOpenGlA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/meme.png", "yes");
	//Actor
	SetScale2D(Vector2{ 0.2, 0.2 }); //scale
	SetPosition2D(Vector2{ -300, 300 }); //location
	//sprite component
	SpriteC* sprite = new SpriteC(this, Asset::GetTexture("yes"));
	AddComponent(sprite);
}

void PlaneTextureOpenGlA::Update()
{
}

void PlaneTextureOpenGlA::Destroy()
{
}
