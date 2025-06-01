#include "Platformer.h"

#include "SpriteC.h"
#include "AnimatedSpriteC.h"
#include "MovingC.h"
#include "Asset.h"
#include "Actor.h"
#include "TheWallA.h"

void Platformer::SetRenderer(IRenderer* pRenderer)
{
	mRenderer = pRenderer;
}

//Initialize scene
void Platformer::Start()
{
	//Actor
	DeathAngelA* actor = new DeathAngelA();
	actor->AttachScene(this);

	AddActor(actor);

	TheWallA* wall = new TheWallA();
	wall->AttachScene(this);

	AddActor(wall);

	for (Actor* actor : mActorsList)
	{
		actor->Start();
	}
}

void Platformer::Update()
{
	mUpdatingActors = true;
	for (Actor* actor : mActorsList)
	{
		actor->Update();
	}
	mUpdatingActors = false;

	// Add pending actors to the pool
	for (Actor* actor : mActorsPending)
	{
		mActorsList.emplace_back(actor);
	}
	mActorsPending.clear();
	for (Actor* deadActor : mDeadActors)
	{
		delete deadActor;
	}
}


//Drawing
void Platformer::Render()
{
	for (Actor* actor : mActorsList)
	{
		actor->Render();
	}
}


void Platformer::Close()
{
}