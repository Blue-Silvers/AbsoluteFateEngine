#pragma once
#include "Scene.h"
#include "Paddle.h"
#include "PongBall.h"
#include "Color.h"
#include "BigBool.h"

class Pong : public Scene
{
private:
	float mPaddleSpeed = 2;
	//int mPlayerMove = 0;
	BigBool mPlayerMove = BigBool::MAYBE;
	int mPoint[2] = { 0,0 };

public:
	Paddle playerPaddle, aiPaddle;
	PongBall pongBall;

	Color redBall = Color::Red;

	Rectangle rRectPlayer = { playerPaddle.mPaddlePositions, playerPaddle.mPaddleDimension };
	Rectangle rRectAi = { aiPaddle.mPaddlePositions, aiPaddle.mPaddleDimension };
	Rectangle rBall = { {pongBall.mBallCenter},{pongBall.mBallRadius,pongBall.mBallRadius} };

	virtual void SetRenderer(Renderer* pRenderer) override;
	virtual void Start() override;
	virtual void Update()override;
	virtual void Render() override;
	virtual void OnInput(SDL_Event) override;
	virtual void  Close() override;

	void Restart();
};