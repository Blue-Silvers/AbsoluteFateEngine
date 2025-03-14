#pragma once
#include "Paddle.h"
#include "Vector2.h"

class PongBall/* : public Actor*/
{
private:
	float mBallSpeedX = 2;
	float mBallSpeedY = 2;
	float mBallSpeedMax = 5;
	
	Paddle* mPlayerPaddle;
	Paddle* mAiPaddle;

public:
	bool mBallLunch = false;
	Vector2 mBallCenter = { 400,400 };
	float mBallRadius = 20;
	bool mBallAlive = true;
	PongBall();
	void Update();
	void Start(Paddle& paddle, Paddle& aiPaddle);
};