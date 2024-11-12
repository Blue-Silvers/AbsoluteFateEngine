#pragma once
#include "Scene.h"
#include "Paddle.h"

class Pong : public Scene
{
private:
	float mPaddleSpeed = 1.5;
	int mPlayerMove = 0;

public:
	Paddle playerPaddle, aiPaddle;

	virtual void SetRenderer(Renderer* pRenderer) override;
	virtual void Start() override;
	virtual void Update()override;
	virtual void Render() override;
	virtual void OnInput(SDL_Event) override;
	virtual void  Close() override;
};

