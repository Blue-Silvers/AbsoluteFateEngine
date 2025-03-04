#include "Actor.h"

#include"Scene.h"
#include"Transform.h"
#include"AnimatedSpriteC.h"

#include"BoxCollider2DC.h"

Actor::Actor() :mState(ActorState::Active),
				mTransform(0, 1, 0),
				mSceneAttached(Scene::ActiveScene)
{
}

Actor::Actor(Transform pTransform2D, Scene* pScene) : mState(ActorState::Active),
														mTransform(pTransform2D),
														mSceneAttached(pScene->ActiveScene)
{

}

void Actor::Render()
{
	mSceneAttached->GetRenderer()->Draw();//draw in renderer

	for (Components* sprite : mComponentsList)
	{
		/*if (SpriteC* spriteComponent = dynamic_cast<SpriteC*>(sprite))
		{
			spriteComponent->Draw(*mSceneAttached->GetRenderer());
		}*/
		if (AnimatedSpriteC* animatedSprite = dynamic_cast<AnimatedSpriteC*>(sprite))
		{
			animatedSprite->Update();
		}
	}
}
