#include "PlaneTextureOpenGlA.h"

#include "SpriteC.h"
#include "Asset.h"
#include <iostream>

void PlaneTextureOpenGlA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Ressources/meme.png", "yes");
	//Actor
	SetScale2D(Vector2{ 1, 1 }); //scale
	SetPosition2D(Vector2{ 0, 0 }); //location
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
