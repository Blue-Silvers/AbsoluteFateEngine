#include "ActorPokeball.h"
#include "MovingC.h"
#include "SpriteC.h"
#include "Asset.h"
#include <iostream>


//ActorPokeball::ActorPokeball(Transform2D pTransform2D, Scene* pScene) : Actor(pTransform2D, pScene)
//{
//	mSceneAttached = pScene;
//}

void ActorPokeball::Start()
{
	//load texture

	/*Asset::LoadTexture(*GetScene()->GetRenderer(), "Picture/pokeball.png", "Pokeball");

	Texture* pokeballTexture = &Asset::GetTexture("Pokeball");
	AddComponent(new SpriteC(this, pokeballTexture, 10));*/
}

void ActorPokeball::Update()
{
	for (Components* move : mComponentsList)
	{
		if (MovingC* movementComponent = dynamic_cast<MovingC*>(move))
		{
			movementComponent->Update();
		}
	}
}

void ActorPokeball::Destroy()
{
}
