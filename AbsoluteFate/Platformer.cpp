#include "Platformer.h"

#include "SpriteC.h"
#include "AnimatedSpriteC.h"
#include "MovingC.h"
#include "Asset.h"
#include "Actor.h"

void Platformer::SetRenderer(Renderer* pRenderer)
{
	mRenderer = pRenderer;
}

//Initialize scene
void Platformer::Start()
{
	//Actor
    //Asset::LoadTexture(*mRenderer, "Ressources/meme.png", "yes");
	DeathAngelA* actor = new DeathAngelA();
	actor->AttachScene(this);

	AddActor(actor);

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


//Input key down
void Platformer::OnInput(SDL_Event event)
{
	for (Actor* actor : mActorsList)
	{
		for (Components* moving : actor->GetAllComponent())
		{
			if (AnimatedSpriteC* anim = dynamic_cast<AnimatedSpriteC*>(moving))
			{
				if (event.key.keysym.sym == SDLK_UP) //Go up if key up is down
				{
					anim->SetAnimationTextures(Asset::GetAnimation("BackWalk"));
				}
				else if (event.key.keysym.sym == SDLK_DOWN) //Go down if key down is down
				{
					anim->SetAnimationTextures(Asset::GetAnimation("FrontWalk"));
				}
				else if (event.key.keysym.sym == SDLK_RIGHT) //Go right if key down is down
				{
					anim->SetAnimationTextures(Asset::GetAnimation("RightWalk"));
				}
				else if (event.key.keysym.sym == SDLK_LEFT) //Go left if key down is down
				{
					anim->SetAnimationTextures(Asset::GetAnimation("LeftWalk"));
				}
				else//Stop movement
				{
					anim->SetAnimationTextures(Asset::GetAnimation("FrontIdle"));
				}
			}
			if (MovingC* movement = dynamic_cast<MovingC*>(moving))
			{
				if (event.key.keysym.sym == SDLK_UP) //Go up if key up is down
				{
					movement->SetSpeed(Vector2D{ 0, 20 });
				}
				else if (event.key.keysym.sym == SDLK_DOWN) //Go down if key down is down
				{
					movement->SetSpeed(Vector2D{ 0, -20 });
				}
				else if (event.key.keysym.sym == SDLK_RIGHT) //Go right if key down is down
				{
					movement->SetSpeed(Vector2D{ 20, 0 });
				}
				else if (event.key.keysym.sym == SDLK_LEFT) //Go left if key down is down
				{
					movement->SetSpeed(Vector2D{ -20, 0 });
				}
				else
				{
					movement->SetSpeed(Vector2D{ 0, 0 }); //Stop movement
				}
			}
		}
	}
}

void Platformer::Close()
{
}
