#include "Actor.h"

#include "IRenderer.h"

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
}