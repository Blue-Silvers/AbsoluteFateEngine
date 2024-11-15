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

	Pong() :Scene("Pong") {};
	void SetRenderer(Renderer* pRenderer) override;
	void Start() override;
	void Update()override;
	void Render() override;
	void OnInput(SDL_Event) override;
	void  Close() override;

	void Restart();
};