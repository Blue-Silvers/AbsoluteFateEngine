#include "Actor.h"
#include"Scene.h"
#include "Transform2D.h"

Actor::Actor() :mState(ActorState::Active),
				mTransform2D(0, 1, 0),
				mSceneAttached(Scene::ActiveScene)
{
}

Actor::Actor(Transform2D pTransform2D, Scene* pScene) : mState(ActorState::Active),
														mTransform2D(pTransform2D),
														mSceneAttached(pScene->ActiveScene)
{

}

void Actor::Render()
{
	for (Components* sprite : mComponentsList)
	{
		sprite->Draw(*mSceneAttached->GetRenderer());
	}
}
