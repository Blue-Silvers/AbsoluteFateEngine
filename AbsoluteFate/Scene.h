#pragma once
#include "Renderer.h"
#include <iostream>
class Scene
{
private:
	std::string mTitle = "Fate Engine";

protected:
	Renderer* mRenderer;

public:

	//Base of scene
	Scene(std::string pTitle = "Scene") :mTitle(pTitle) {};
	virtual void SetRenderer(Renderer* pRenderer)
	{
		mRenderer = pRenderer;
	};
	virtual void Start() {};
	virtual void Update() {};
	virtual void Render() {};
	virtual void OnInput(SDL_Event) {};
	virtual void  Close() {};

};

