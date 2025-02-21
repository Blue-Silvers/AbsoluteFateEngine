#include "DeathAngelA.h"

#include "PlayerController.h"
#include "Asset.h"
#include "BoxCollider2DC.h"
#include "AnimatedSpriteC.h"
#include <iostream>

void DeathAngelA::Start()
{
	//load texture
	Asset::LoadAllTextureFromFolder(*mSceneAttached->GetRenderer(), "Ressources/Anim/DeathAngel/Idle/FrontIdle", "FrontIdle");
	Asset::LoadAllTextureFromFolder(*mSceneAttached->GetRenderer(), "Ressources/Anim/DeathAngel/Idle/BackIdle", "BackIdle");
	Asset::LoadAllTextureFromFolder(*mSceneAttached->GetRenderer(), "Ressources/Anim/DeathAngel/Idle/RightIdle", "RightIdle");
	Asset::LoadAllTextureFromFolder(*mSceneAttached->GetRenderer(), "Ressources/Anim/DeathAngel/Idle/LeftIdle", "LeftIdle");
	Asset::LoadAllTextureFromFolder(*mSceneAttached->GetRenderer(), "Ressources/Anim/DeathAngel/Walk/FrontWalk", "FrontWalk");
	Asset::LoadAllTextureFromFolder(*mSceneAttached->GetRenderer(), "Ressources/Anim/DeathAngel/Walk/BackWalk", "BackWalk");
	Asset::LoadAllTextureFromFolder(*mSceneAttached->GetRenderer(), "Ressources/Anim/DeathAngel/Walk/LeftWalk", "LeftWalk");
	Asset::LoadAllTextureFromFolder(*mSceneAttached->GetRenderer(), "Ressources/Anim/DeathAngel/Walk/RightWalk", "RightWalk");

	//Actor
	SetScale(Vector2D{ 1, 1 }); //scale
	SetPosition(Vector2D{ 400, 400 }); //location
	//anim component
	AnimatedSpriteC* animation = new AnimatedSpriteC(this, Asset::GetAnimation("FrontIdle"));
	animation->SetAnimationFps(10);
	AddComponent(animation);
	//move component
	PlayerController* movement = new PlayerController(this);
	movement->SetSpeed(Vector2D{ 0, 0 });
	AddComponent(movement);
	//Box collider component

	Transform2D destinationRect = Transform2D( //debug box
								Vector2D(static_cast<int>(GetTransform2D().GetPosition().x - animation->GetTexWidth()/2.0f),
										static_cast<int>(GetTransform2D().GetPosition().y - animation->GetTexHeight() / 2.0f)),
								Vector2D(static_cast<int>(animation->GetTexWidth() * GetTransform2D().GetScale().x),
											static_cast<int>(animation->GetTexHeight() * GetTransform2D().GetScale().y)),
								GetTransform2D().GetRotation());

	BoxCollider2DC* boxCollider2DC = new BoxCollider2DC(destinationRect, this);//get sprite transform
	AddComponent(boxCollider2DC);
}

void DeathAngelA::Update()
{
	for (Components* move : mComponentsList)
	{
		if (PlayerController* movementComponent = dynamic_cast<PlayerController*>(move))
		{
			movementComponent->Update();
		}
		move->Update();
	}
}

void DeathAngelA::Destroy()
{
}
