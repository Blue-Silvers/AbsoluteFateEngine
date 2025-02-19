#include "DeathAngelA.h"
#include "MovingC.h"
#include "PlayerController.h"
#include "SpriteC.h"
#include "Asset.h"
#include <iostream>

#include "AnimatedSpriteC.h"
#include "Actor.h"

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
}

void DeathAngelA::Update()
{
	for (Components* move : mComponentsList)
	{
		if (PlayerController* movementComponent = dynamic_cast<PlayerController*>(move))
		{
			movementComponent->Update();
		}
	}
}

void DeathAngelA::Destroy()
{
}
