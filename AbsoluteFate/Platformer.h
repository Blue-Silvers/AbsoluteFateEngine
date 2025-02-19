#pragma once
#include "Scene.h"
#include "BigBool.h"

#include "DeathAngelA.h"
class Platformer : public Scene
{
	float mPaddleSpeed = 2;
	//int mPlayerMove = 0;
	BigBool mPlayerMove = BigBool::MAYBE;

public:


	Platformer() :Scene("Platformer") {};
	void SetRenderer(Renderer* pRenderer) override;
	void Start() override;
	void Update()override;
	void Render() override;
	void OnInput(SDL_Event) override;
	void  Close() override;
};

