#pragma once
#include "Window.h"
#include "Renderer.h"
class Game
{
private:
	std::string mTitle = "Fate Engine";
	Window* mWindow;
	Renderer* mRenderer;
	bool mIsRunning;

public:
	
	Game(std::string gameTitle);
	Game(const Game&) = delete;
	Game& operator= (const Game&) = delete;

	void Init();
	void Loop();//chore
	void Render();
	void Update();//gameplay
	void CheckInput();
	void Close();

};

