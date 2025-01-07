#pragma once
#include "Renderer.h"
#include <iostream>
#include <vector>
class Actor;

class Scene
{
private:
	std::string mTitle = "Fate Engine";
	std::vector<Actor*> mActorsList{};

protected:
	Renderer* mRenderer;

public:

	//Base of scene
	Scene(std::string pTitle = "Scene") :mTitle(pTitle) {};
	virtual ~Scene();

	virtual void SetRenderer(Renderer* pRenderer)
	{
		mRenderer = pRenderer;
	};
	virtual void Start();
	virtual void Update();
	virtual void Render() {};
	virtual void OnInput(SDL_Event) {};
	virtual void  Close() {};

	//Actors
	void AddActor(Actor* newActor);
	void RemoveActor(Actor* deadActor);
};

