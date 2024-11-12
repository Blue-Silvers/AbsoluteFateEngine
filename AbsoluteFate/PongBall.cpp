#include "PongBall.h"
#include <SDL.h>
PongBall::PongBall()
{

}

void PongBall::Start(Paddle& paddle, Paddle& aiPaddle)
{
	mBallCenterX = 400;
	mBallCenterY = 400;
	mBallRadius = 15;
	mBallSpeedX = 2;
	mBallSpeedY = 2;
	mPlayerPaddle = &paddle;
	//mAiPaddle = &aiPaddle;
	mBallLife = 3;
	mBallLunch = false;
}

void PongBall::Update()
{
	//if (IsKeyDown(KEY_SPACE))
	//{
	//	mBallLunch = true;
	//}

	if (mBallLunch)
	{
		mBallCenterX += mBallSpeedX;
		if ((mBallCenterX >= 800 - mBallRadius / 2 && mBallSpeedX > 0) || (mBallCenterX <= mBallRadius / 2 && mBallSpeedX < 0))
		{
			mBallSpeedX *= -1;
		}

		mBallCenterY += mBallSpeedY;
		if ((mBallCenterY >= 800 - mBallRadius / 2 && mBallSpeedY > 0) || (mBallCenterY <= mBallRadius / 2 && mBallSpeedY < 0))
		{
			mBallSpeedY *= -1;
		}

		if (mBallCenterY + mBallRadius >= mPlayerPaddle->mPaddleY && mBallCenterX + mBallRadius > mPlayerPaddle->mPaddleX && mBallCenterX - mBallRadius < mPlayerPaddle->mPaddleX + mPlayerPaddle->mPaddleWidth)
		{
			if (mBallCenterX > mPlayerPaddle->mPaddleX + mPlayerPaddle->mPaddleWidth / 2)
			{
				float distanceRight = mPlayerPaddle->mPaddleX + mPlayerPaddle->mPaddleWidth / 2 - mBallCenterX;
				mBallSpeedX = -mBallSpeedMax * (distanceRight / (newPaddle->mPaddleWidth / 2));
			}
			else if (mBallCenterX < mPlayerPaddle->mPaddleX + mPlayerPaddle->mPaddleWidth / 2)
			{
				float distanceLeft = newPaddle->mPaddleX + newPaddle->mPaddleWidth / 2 - mBallCenterX;
				mBallSpeedX = -mBallSpeedMax * (distanceLeft / (newPaddle->mPaddleWidth / 2));
			}
			else
			{
				mBallCenterX = 0;
			}
			mBallSpeedY *= -1;
		}

	}
	else
	{
		mBallSpeedX = 2;
		mBallSpeedY = -2;
		mBallCenterX = 400;
		mBallCenterY = 400;

		mBallLunch = false;

	}
}


void PongBall::Draw()
{
	Circle DrawCircle(mBallCenterX, mBallCenterY, mBallRadius, mBallColor);
}

void PongBall::CollideBrick()
{
	mBallSpeedX *= -1;
}