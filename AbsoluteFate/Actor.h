#pragma once
#include"Scene.h"
#include "Transform2D.h"
#include "Components.h"
#include <vector>

class Components; 
class Scene;

// Know if the Actor should be rendered / updated or destroyed
enum class ActorState {
	Active,
	Paused,
	Dead
};

class Actor
{
private:
	Scene* mSceneAttached;
	ActorState mState = ActorState::Active;
	Transform2D mTransforform2D;
	std::vector<Components*> mComponentsList;

public:
	Actor();
	virtual void Start() = 0;
	virtual void AttachScene(Scene* pSceneAttached) //A reference to the scene it is attached to
	{
		mSceneAttached = pSceneAttached;
	};
	virtual void AddComponent(Components* pComponents) //Add new components
	{
		mComponentsList.push_back(pComponents);
	};
	virtual void RemoveComponent(int index) //Remove one component
	{
		if (index >= 0 && index < mComponentsList.size()) {
			mComponentsList.erase(mComponentsList.begin() + index);
		}
	};
	virtual void ClearComponent() //Delette all components
	{
		mComponentsList.clear();
	};
	virtual void SetActive(ActorState pState) //Change state
	{
		mState = pState;
	};
	virtual void Update() = 0;
	virtual void Destroy() = 0;
};

