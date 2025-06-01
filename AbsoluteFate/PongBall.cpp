#include "PongBall.h"
#include <SDL.h>
#include "RendererSDL.h"

PongBall::PongBall()
{

}

//reset all value
void PongBall::Start(Paddle& paddle, Paddle& aiPaddle)
{
	mBallCenter.x = 400;
	mBallCenter.y = 400;
	mBallRadius = 20;
	mBallSpeedX = 2;
	mBallSpeedY = 2;
	mPlayerPaddle = &paddle; //Define player paddle
	mAiPaddle = &aiPaddle; //Define ai paddle
	mBallAlive = true;
	mBallLunch = false;
}

void PongBall::Update()
{

	//ball moving and check collision only if is lunching
	if (mBallLunch)
	{
		mBallCenter.x += mBallSpeedX; //move ball in x axis

		//Check if the ball collide right or left window wall
		if ((mBallCenter.x >= 800 - mBallRadius / 2 && mBallSpeedX > 0) || (mBallCenter.x <= mBallRadius / 2 && mBallSpeedX < 0))
		{
			mBallAlive = false; //game over
		}

		//Check if the ball collide right or left window wall
		mBallCenter.y += mBallSpeedY;
		if ((mBallCenter.y >= 800 - mBallRadius / 2 && mBallSpeedY > 0) || (mBallCenter.y <= mBallRadius / 2 && mBallSpeedY < 0))
		{
			mBallSpeedY *= -1; // bounes ball
		}

		//Ball collide mPlayerPaddle
		if (mBallCenter.y <= mPlayerPaddle->mPaddlePositions.y + mPlayerPaddle->mPaddleDimension.y && mBallCenter.y + mBallRadius >= mPlayerPaddle->mPaddlePositions.y 
			&& mBallCenter.x + mBallRadius > mPlayerPaddle->mPaddlePositions.x && mBallCenter.x - mBallRadius < mPlayerPaddle->mPaddlePositions.x + mPlayerPaddle->mPaddleDimension.y)
		{
			//Ball bounes whith angle and speed changing in fonction of collide location whith player paddle
			if (mBallCenter.y < mPlayerPaddle->mPaddlePositions.y + mPlayerPaddle->mPaddleDimension.y / 2) //Check if the ball is above the middle of player paddle
			{
				float distanceRight = mPlayerPaddle->mPaddlePositions.y + mPlayerPaddle->mPaddleDimension.y / 2 - mBallCenter.y; //Verify distance between the ball collision and player paddle
				mBallSpeedY = -mBallSpeedMax * (distanceRight / (mPlayerPaddle->mPaddleDimension.y / 2)); //Bounes and change speed whith max speed and distance between the ball collision and player paddle
			}
			else if (mBallCenter.y > mPlayerPaddle->mPaddlePositions.y + mPlayerPaddle->mPaddleDimension.y / 2) //Check if the ball is below the middle of player paddle
			{
				float distanceLeft = mPlayerPaddle->mPaddlePositions.y + mPlayerPaddle->mPaddleDimension.y / 2 - mBallCenter.y;//Verify distance between the ball collision and player paddle
				mBallSpeedY = -mBallSpeedMax * (distanceLeft / (mPlayerPaddle->mPaddleDimension.y / 2));//Bounes and change speed whith max speed and distance between the ball collision and player paddle
			}
			else //The ball is on middle of player paddle
			{
				mBallSpeedY = 0; //Ball have horizontal movement
			}
			mBallSpeedX *= -1;
		}

		//Ball collide mAiPaddle
		if (mBallCenter.y <= mAiPaddle->mPaddlePositions.y + mAiPaddle->mPaddleDimension.y && mBallCenter.y + mBallRadius >= mAiPaddle->mPaddlePositions.y && mBallCenter.x + mBallRadius > mAiPaddle->mPaddlePositions.x && mBallCenter.x - mBallRadius < mAiPaddle->mPaddlePositions.x + mAiPaddle->mPaddleDimension.x - mBallRadius)
		{
			//Ball bounes whith angle and speed changing in fonction of collide location whith ai paddle
			if (mBallCenter.y < mAiPaddle->mPaddlePositions.y + mAiPaddle->mPaddleDimension.y / 2)//Check if the ball is above the middle of ai paddle
			{
				float distanceRight = mAiPaddle->mPaddlePositions.y + mAiPaddle->mPaddleDimension.y / 2 - mBallCenter.y;//Verify distance between the ball collision and ai paddle
				mBallSpeedY = -mBallSpeedMax * (distanceRight / (mAiPaddle->mPaddleDimension.y / 2));//Bounes and change speed whith max speed and distance between the ball collision and ai paddle
			}
			else if (mBallCenter.y > mAiPaddle->mPaddlePositions.y + mAiPaddle->mPaddleDimension.y / 2) //Check if the ball is below the middle of ai paddle
			{
				float distanceLeft = mAiPaddle->mPaddlePositions.y + mAiPaddle->mPaddleDimension.y / 2 - mBallCenter.y;//Verify distance between the ball collision and ai paddle
				mBallSpeedY = -mBallSpeedMax * (distanceLeft / (mAiPaddle->mPaddleDimension.y / 2));//Bounes and change speed whith max speed and distance between the ball collision and ai paddle
			}
			else //The ball is on middle of ai paddle
			{
				mBallSpeedY = 0; //Ball have horizontal movement
			}
			mBallSpeedX *= -1;
		}

	}
	else
	{
		//reset ball position and speed
		mBallSpeedX = 2;
		mBallSpeedY = -2;
		mBallCenter.x = 400;
		mBallCenter.y = 400;

		mBallLunch = false;
	}
}