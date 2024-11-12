#pragma once
#include "Paddle.h"

class PongBall
{
private:
	float mBallSpeedX = 2;
	float mBallSpeedY = 2;
	float mBallSpeedMax = 5;
	bool mBallLunch = false;
	Paddle* mPlayerPaddle, mAiPaddle;

public:
	float mBallCenterX = 400;
	float mBallCenterY = 400;
	int mBallRadius = 20;
	int mBallLife = 3;
	PongBall();
	void Update();
	void Start(Paddle& paddle, Paddle& aiPaddle);
	void Draw();
	void CollideBrick();
};