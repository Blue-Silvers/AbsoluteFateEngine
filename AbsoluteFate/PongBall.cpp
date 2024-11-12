#include "PongBall.h"
#include <SDL.h>
#include "Renderer.h"

PongBall::PongBall()
{

}

void PongBall::Start(Paddle& paddle, Paddle& aiPaddle)
{
	mBallCenter.x = 400;
	mBallCenter.y = 400;
	mBallRadius = 20;
	mBallSpeedX = 2;
	mBallSpeedY = 2;
	mPlayerPaddle = &paddle;
	mAiPaddle = &aiPaddle;
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
		mBallCenter.x += mBallSpeedX;
		if ((mBallCenter.x >= 800 - mBallRadius / 2 && mBallSpeedX > 0) || (mBallCenter.x <= mBallRadius / 2 && mBallSpeedX < 0))
		{
			mBallSpeedX *= -1;
		}

		mBallCenter.y += mBallSpeedY;
		if ((mBallCenter.y >= 800 - mBallRadius / 2 && mBallSpeedY > 0) || (mBallCenter.y <= mBallRadius / 2 && mBallSpeedY < 0))
		{
			mBallSpeedY *= -1;
		}

		if (mBallCenter.y + mBallRadius >= mPlayerPaddle->mPaddlePositions.y && mBallCenter.x + mBallRadius > mPlayerPaddle->mPaddlePositions.x && mBallCenter.x - mBallRadius < mPlayerPaddle->mPaddlePositions.x + mPlayerPaddle->mPaddleDimension.y)
		{
			if (mBallCenter.x > mPlayerPaddle->mPaddlePositions.x + mPlayerPaddle->mPaddleDimension.y / 2)
			{
				float distanceRight = mPlayerPaddle->mPaddlePositions.y + mPlayerPaddle->mPaddleDimension.y / 2 - mBallCenter.x;
				mBallSpeedX = -mBallSpeedMax * (distanceRight / (mPlayerPaddle->mPaddleDimension.y / 2));
			}
			else if (mBallCenter.x < mPlayerPaddle->mPaddlePositions.y + mPlayerPaddle->mPaddleDimension.y / 2)
			{
				float distanceLeft = mPlayerPaddle->mPaddlePositions.y + mPlayerPaddle->mPaddleDimension.y / 2 - mBallCenter.x;
				mBallSpeedX = -mBallSpeedMax * (distanceLeft / (mPlayerPaddle->mPaddleDimension.y / 2));
			}
			else
			{
				mBallCenter.x = 0;
			}
			mBallSpeedY *= -1;
		}
		//mAiPaddle
		if (mBallCenter.y + mBallRadius >= mAiPaddle->mPaddlePositions.y && mBallCenter.x + mBallRadius > mAiPaddle->mPaddlePositions.x && mBallCenter.x - mBallRadius < mAiPaddle->mPaddlePositions.x + mAiPaddle->mPaddleDimension.y)
		{
			if (mBallCenter.x > mAiPaddle->mPaddlePositions.x + mAiPaddle->mPaddleDimension.y / 2)
			{
				float distanceRight = mAiPaddle->mPaddlePositions.y + mAiPaddle->mPaddleDimension.y / 2 - mBallCenter.x;
				mBallSpeedX = -mBallSpeedMax * (distanceRight / (mAiPaddle->mPaddleDimension.y / 2));
			}
			else if (mBallCenter.x < mAiPaddle->mPaddlePositions.y + mAiPaddle->mPaddleDimension.y / 2)
			{
				float distanceLeft = mAiPaddle->mPaddlePositions.y + mAiPaddle->mPaddleDimension.y / 2 - mBallCenter.x;
				mBallSpeedX = -mBallSpeedMax * (distanceLeft / (mAiPaddle->mPaddleDimension.y / 2));
			}
			else
			{
				mBallCenter.x = 0;
			}
			mBallSpeedY *= -1;
		}

	}
	else
	{
		mBallSpeedX = 2;
		mBallSpeedY = -2;
		mBallCenter.x = 400;
		mBallCenter.y = 400;

		mBallLunch = false;

	}
}

