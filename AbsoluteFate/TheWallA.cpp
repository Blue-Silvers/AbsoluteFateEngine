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
	SetScale(Vector2D{ 1, 1 }); //scale
	SetPosition(Vector2D{ 1000, 400}); //location
	//sprite component
	SpriteC* sprite = new SpriteC(this, Asset::GetTexture("yes"));
	AddComponent(sprite);
	//Box collider component
	Transform2D destinationRect = Transform2D( //debug box
		Vector2D(static_cast<int>(GetTransform2D().GetPosition().x - sprite->GetTexWidth() / 2.0f),
			static_cast<int>(GetTransform2D().GetPosition().y - sprite->GetTexHeight() / 2.0f)),
		Vector2D(static_cast<int>(sprite->GetTexWidth() * GetTransform2D().GetScale().x),
			static_cast<int>(sprite->GetTexHeight() * GetTransform2D().GetScale().y)),
		GetTransform2D().GetRotation());

	BoxCollider2DC* boxCollider2DC = new BoxCollider2DC(destinationRect, this);
	AddComponent(boxCollider2DC);
}

void TheWallA::Update()
{
}

void TheWallA::Destroy()
{
}
