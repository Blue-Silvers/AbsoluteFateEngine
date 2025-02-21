#pragma once
#include "Window.h"
#include "Renderer.h"
#include "Scene.h"
#include "Time.h"

class Game
{
private:
	std::string mTitle = "Fate Engine";
	Window* mWindow;
	RendererSDL* mRenderer;
	Scene* mScene[1] = {nullptr};
	int mLoadedScene = 0;
	bool mIsRunning;

public:
	
	SDL_Event event;

	Game(std::string gameTitle, Scene* newScene);
	Game(const Game&) = delete;
	Game& operator= (const Game&) = delete;

	void Init(Scene* newScene);
	void Loop();//chore
	void Render();
	void Update();//gameplay
	void CheckInput();
	void Close();

};

