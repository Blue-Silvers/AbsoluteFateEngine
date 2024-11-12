#pragma once
#include "Scene.h"

class Pong : public Scene
{
	virtual void SetRenderer(Renderer* pRenderer) override;
	virtual void Start() override;
	virtual void Update()override;
	virtual void Render() override;
	virtual void OnInput(SDL_Event) override;
	virtual void  Close() override;
};

