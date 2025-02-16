#pragma once
#include "Scene.h"
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
protected:
	Scene* mSceneAttached;
	ActorState mState;
	Transform2D mTransform2D;
	std::vector<Components*> mComponentsList; //DrawSprite(Actor& pActor, Texture& pTexture, Rectangle pSourceRect, Vector2D pOrigin, Flip pFlip)

public:
	Actor();
	Actor(Transform2D pTransform2D, Scene* pScene);
	
	virtual void Start() = 0;
	void Render();
	virtual void AttachScene(Scene* pSceneAttached) //A reference to the scene it is attached to
	{
		mSceneAttached = pSceneAttached;
	};
	virtual void AddComponent(Components* pComponents) //Add new components
	{
		mComponentsList.push_back(pComponents);
	};
	virtual std::vector<Components*> GetAllComponent() //get components
	{
		return mComponentsList;
	};
	virtual void RemoveComponent(int index) //Remove one component
	{
		if (index >= 0 && mComponentsList.size() > index) 
		{
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
	virtual void SetPosition(Vector2D pNewPosition) //set position
	{
		mTransform2D = Transform2D(pNewPosition, mTransform2D.GetScale(), mTransform2D.GetRotation());
	};
	virtual void SetScale(Vector2D pNewScale) //set scale
	{
		mTransform2D = Transform2D(mTransform2D.GetPosition(), pNewScale, mTransform2D.GetRotation());
	};
	virtual void Update() = 0;
	virtual void Destroy() = 0;

	//Getter
	virtual Scene* GetScene()
	{
		return mSceneAttached;
	};	
	virtual Transform2D GetTransform2D()
	{
		return mTransform2D;
	};

	//template fonction
	template<typename  C>
	C* GetComponentOfType() const
	{
		C* result = nullptr;
		for (Components* component : mComponentsList)
		{
			result = dynamic_cast<C*>(component);
			if (result != nullptr) return result;
		}
		return nullptr;
	}

};

