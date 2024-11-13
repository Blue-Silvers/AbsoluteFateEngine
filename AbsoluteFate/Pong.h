#pragma once
#include "Scene.h"
#include "Paddle.h"
#include "PongBall.h"

class Pong : public Scene
{
private:
	float mPaddleSpeed = 2;
	int mPlayerMove = 0;

public:
	Paddle playerPaddle, aiPaddle;
	PongBall pongBall;

	virtual void SetRenderer(Renderer* pRenderer) override;
	virtual void Start() override;
	virtual void Update()override;
	virtual void Render() override;
	virtual void OnInput(SDL_Event) override;
	virtual void  Close() override;
};

