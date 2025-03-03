#include "TheWallA.h"

#include "BoxCollider2DC.h"
#include "SpriteC.h"
#include "Asset.h"
#include <iostream>

void TheWallA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Ressources/meme.png", "yes");
	//Actor
	SetScale2D(Vector2{ 1, 1 }); //scale
	SetPosition2D(Vector2{ 1000, 400}); //location
	//sprite component
	SpriteC* sprite = new SpriteC(this, Asset::GetTexture("yes"));
	AddComponent(sprite);
	//Box collider component
	BoxCollider2DC* boxCollider2DC = new BoxCollider2DC( this);
	AddComponent(boxCollider2DC);
}

void TheWallA::Update()
{
}

void TheWallA::Destroy()
{
}
