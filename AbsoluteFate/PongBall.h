#pragma once
#include "Paddle.h"
#include "Vector2D.h"

class PongBall
{
private:
	float mBallSpeedX = 2;
	float mBallSpeedY = 2;
	float mBallSpeedMax = 5;
	
	Paddle* mPlayerPaddle;
	Paddle* mAiPaddle;

public:
	bool mBallLunch = false;
	Vector2D mBallCenter = { 400,400 };
	//float mBallCenterX = 400;
	//float mBallCenterY = 400;
	float mBallRadius = 20;
	int mBallLife = 3;
	PongBall();
	void Update();
	void Start(Paddle& paddle, Paddle& aiPaddle);
};