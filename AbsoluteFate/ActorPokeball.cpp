#include "ActorPokeball.h"
#include "SpriteC.h"
#include "Asset.h"
#include <iostream>

ActorPokeball::ActorPokeball(Transform2D pTransform2D, Scene* pScene) : Actor(pTransform2D, pScene)
{
}

void ActorPokeball::Start()
{
	//load texture

	Asset::LoadTexture(*GetScene()->GetRenderer(), "Picture/pokeball.png", "Pokeball");

	Texture* pokeballTexture = &Asset::GetTexture("Pokeball");
	AddComponent(new SpriteC(this, pokeballTexture, 10));
}

void ActorPokeball::Update()
{
}

void ActorPokeball::Destroy()
{
}
