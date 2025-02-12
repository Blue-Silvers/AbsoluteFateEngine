#include "ActorPokeball.h"
#include "SpriteC.h"

void ActorPokeball::Start()
{
	Texture* pokeballTexture = new Texture();
	pokeballTexture->LoadTexture(*GetScene()->GetRenderer(), "Picture/pokeball.png");
	AddComponent(new SpriteC(this, pokeballTexture, 2));
}

void ActorPokeball::Update()
{
}

void ActorPokeball::Destroy()
{
}
