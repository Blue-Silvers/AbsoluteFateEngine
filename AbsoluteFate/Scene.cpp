#include "Scene.h"

#include "Actor.h"
#include "Asset.h"

//Reset scene
Scene::~Scene()
{
	for (Actor* actor : mActorsList)
	{
		delete actor;
	}
}

Scene* Scene::ActiveScene = nullptr; //handling actors

void Scene::Start()
{
	for (Actor* actor : mActorsList)
	{
		actor->Start();
	}
}

void Scene::Update()
{
	UpdateAllActors();
}

void Scene::Render()
{
	for (Actor* actor : mActorsList)
	{
		actor->Render();
	}
}

void Scene::AddActor(Actor* newActor)
{
	//Add actor in the scene
	newActor->AttachScene(this);
	
	if (mUpdatingActors) 
	{
		mActorsPending.emplace_back(newActor);
	}
	else 
	{
		mActorsList.push_back(newActor);
	}

}

void Scene::UpdateAllActors()
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

void Scene::RemoveActor(Actor* deadActor)
{
	std::vector<Actor*>::iterator it = find(mActorsPending.begin(), mActorsPending.end(), deadActor);
	if (it != mActorsPending.end())
	{
		std::iter_swap(it, mActorsPending.end() - 1);
		mActorsPending.pop_back();
	}
	it = find(mActorsList.begin(), mActorsList.end(), deadActor);
	if (it != mActorsList.end())
	{
		std::iter_swap(it, mActorsList.end() - 1);
		mActorsList.pop_back();
	}
}

void Scene::Load()
{

}

void Scene::Unload()
{
	//Free actors pointers memory
	while (!mActorsList.empty())
	{
		delete mActorsList.back();
	}
	//Free up resources
	Asset::ClearMap();
}