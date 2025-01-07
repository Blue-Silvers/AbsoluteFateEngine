#include "Scene.h"
#include "Actor.h"

//Reset scene
Scene::~Scene()
{
	for (Actor* actor : mActorsList)
	{
		delete actor;
	}
}

void Scene::Start()
{
	for (Actor* actor : mActorsList)
	{
		actor->Start();
	}
}

void Scene::Update()
{
	for (Actor* actor : mActorsList)
	{
		actor->Update();
	}
}

void Scene::AddActor(Actor* newActor)
{
	//Add actor in the scene
	mActorsList.push_back(newActor);
	newActor->AttachScene(this);
	newActor->Start();
}

void Scene::RemoveActor(Actor* deadActor)
{
	for (int i = 0; i < mActorsList.size(); i++)
	{
		if (mActorsList[i] == deadActor)
		{
			mActorsList.erase(mActorsList.begin() + i);
		}
	}
	deadActor->Destroy();
}
