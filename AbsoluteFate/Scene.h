#pragma once
#include "Renderer.h"
#include <iostream>
#include <vector>
#include <algorithm>

class Actor;
class Renderer;

class Scene
{
protected:
	std::string mTitle = "Fate Engine";
	std::vector<Actor*> mActorsList{};
	std::vector<Actor*> mActorsPending{};
	bool mUpdatingActors;
	std::vector<Actor*> mDeadActors{};

protected:
	Renderer* mRenderer;

public:
	static Scene* ActiveScene;//handling actors
	//Base of scene
	Scene(std::string pTitle = "Scene") : mTitle(pTitle), mUpdatingActors(false) {};
	virtual ~Scene();

	virtual void SetRenderer(Renderer* pRenderer)
	{
		mRenderer = pRenderer;
	};
	virtual Renderer* GetRenderer()
	{
		return mRenderer;
	};
	virtual std::vector<Actor*> GetAllActor()
	{
		return mActorsList;
	};
	virtual void Start();
	virtual void Update();
	virtual void Render();
	virtual void OnInput(SDL_Event) {}; //replace by MovingC and InputManager
	virtual void Close() {};

	//Actors
	void AddActor(Actor* newActor);
	void UpdateAllActors();
	void RemoveActor(Actor* deadActor);

	void Load();
	void Unload();
};

