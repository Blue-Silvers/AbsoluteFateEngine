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
	SetScale2D(Vector2{ 1, 1 }); //scale
	SetPosition2D(Vector2{ 100, 100 }); //location

	//mTransform.RotateZInDegrees(90);
	
	//anim component
	AnimatedSpriteC* animation = new AnimatedSpriteC(this, Asset::GetAnimation("FrontIdle"));
	animation->SetAnimationFps(5);
	AddComponent(animation);
	//move component
	PlayerController* movement = new PlayerController(this);
	movement->SetSpeed(Vector3{0, 0, 0 });
	AddComponent(movement);
	//Box collider component

	BoxCollider2DC* boxCollider2DC = new BoxCollider2DC(this);//get sprite transform
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
