#include "Actor.h"
#include"Scene.h"
#include "Transform2D.h"

Actor::Actor(Transform2D pTransform2D, Scene* pScene) : mState(ActorState::Active),
mSceneAttached(pScene->ActiveScene),
mTransforform2D(pTransform2D)
{

}