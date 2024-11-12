#pragma once
#include "Window.h"
#include "Renderer.h"
#include "Scene.h"

class Game
{
private:
	std::string mTitle = "Fate Engine";
	Window* mWindow;
	Renderer* mRenderer;
	Scene* mScene[1] = {nullptr};
	bool mIsRunning;

public:
	
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

