#pragma once
#include "Window.h"
#include "IRenderer.h"
#include "Scene.h"
#include "Time.h"

class Game
{
private:
	std::string mTitle = "Fate Engine";
	Window* mWindow;
	IRenderer* mRenderer;
	Scene* mScene[1] = {nullptr};
	int mLoadedScene = 0;
	bool mIsRunning;
	IRenderer::RendererType mRendererType;

public:
	SDL_Event event;

	//Constructor
	Game(std::string gameTitle, Scene* newScene, IRenderer::RendererType pRendererType);
	Game(const Game&) = delete;
	Game& operator= (const Game&) = delete;

	//Base fonctions
	void Init(Scene* newScene); //Initialazer
	void Loop();//core
	void Render();
	void Update();//gameplay
	void CheckInput();
	void Close();
};