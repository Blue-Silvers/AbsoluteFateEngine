#pragma once
#include "Scene.h"
#include "Transform.h"
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
	std::vector<std::string> mTagList = {}; //all tag of Actor

protected:
	Scene* mSceneAttached;
	ActorState mState;
	Transform mTransform;
	std::vector<Components*> mComponentsList; //DrawSprite(Actor& pActor, Texture& pTexture, Rectangle pSourceRect, Vector2D pOrigin, Flip pFlip)

public:
	Actor();
	Actor(Transform pTransform2D, Scene* pScene);
	
	virtual void Start() = 0;
	virtual void Render();
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
	virtual void SetPosition2D(Vector2 pNewPosition) //set position 2D
	{
		mTransform = Transform(pNewPosition, mTransform.GetScale2D(), mTransform.GetRotation2D());
		mTransform.ComputeWorldTransform();
	};
	virtual void SetScale2D(Vector2 pNewScale) //set scale 2D
	{
		mTransform = Transform(mTransform.GetPosition2D(), pNewScale, mTransform.GetRotation2D());
		mTransform.ComputeWorldTransform();
	};
	virtual void SetRotation2D(float pNewRotation) //set rotation 2D
	{
		mTransform = Transform(mTransform.GetPosition2D(), mTransform.GetScale2D(), pNewRotation);
		mTransform.ComputeWorldTransform();
	};
	virtual void SetPosition(Vector3 pNewPosition) //set position
	{
		mTransform = Transform(pNewPosition, mTransform.GetScale(), mTransform.GetRotation());
		mTransform.ComputeWorldTransform();
	};
	virtual void SetScale(Vector3 pNewScale) //set scale
	{
		mTransform = Transform(mTransform.GetPosition(), pNewScale, mTransform.GetRotation());
		mTransform.ComputeWorldTransform();
	};
	virtual void SetRotation(Quaternion pNewRotation) //set rotation
	{
		mTransform = Transform(mTransform.GetPosition(), mTransform.GetScale(), pNewRotation);
		mTransform.ComputeWorldTransform();
	};
	virtual void SetTags(std::vector<std::string> pTags) //set tag list
	{
		mTagList = pTags;
	};
	virtual void AddTag(std::string pTag) //add tag
	{
		mTagList.push_back(pTag);
	};
	virtual void RemoveTag(int index) //Remove one tag
	{
		if (index >= 0 && mTagList.size() > index)
		{
			mTagList.erase(mTagList.begin() + index);
		}
	};
	virtual void ClearTag() //Delette all tag
	{
		mTagList.clear();
	};
	virtual void Update() = 0;
	virtual void Destroy() = 0;

	//Getter
	virtual Scene* GetScene()
	{
		return mSceneAttached;
	};	
	virtual Transform GetTransform()
	{
		return mTransform;
	};
	virtual std::vector<std::string> GetTags()
	{
		return mTagList;
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

