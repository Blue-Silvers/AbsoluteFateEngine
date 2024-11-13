#include "Pong.h"

void Pong::SetRenderer(Renderer* pRenderer)
{
	mRenderer = pRenderer;
}

void Pong::Start()
{
	mPoint[0] = 0;
	mPoint[1] = 0;
	aiPaddle.mPaddlePositions = { 65,300 };
	playerPaddle.mPaddlePositions = { 700,300 };
	pongBall.Start(playerPaddle, aiPaddle);
}

void Pong::Restart()
{
	aiPaddle.mPaddlePositions = { 65,300 };
	playerPaddle.mPaddlePositions = { 700,300 };
	pongBall.Start(playerPaddle, aiPaddle);
}

void Pong::Update()
{
	if (pongBall.mBallAlive == false)
	{
		if (pongBall.mBallCenter.x >= 800 - pongBall.mBallRadius / 2 || pongBall.mBallCenter.x <= pongBall.mBallRadius / 2)
		{
			mPoint[0] += 1;
		}
		else if(pongBall.mBallCenter.x <= pongBall.mBallRadius / 2)
		{
			mPoint[1] += 1;
		}
		Restart();
	}

	if (aiPaddle.mPaddlePositions.y > 0 && pongBall.mBallCenter.y < aiPaddle.mPaddlePositions.y + aiPaddle.mPaddleDimension.y/3)
	{
		aiPaddle.mPaddlePositions.y -= mPaddleSpeed;
	}
	else if (aiPaddle.mPaddlePositions.y < 600 && pongBall.mBallCenter.y > aiPaddle.mPaddlePositions.y + (aiPaddle.mPaddleDimension.y / 3)*2)
	{
		aiPaddle.mPaddlePositions.y += mPaddleSpeed;
	}


	if (playerPaddle.mPaddlePositions.y > 0 && mPlayerMove == 1)
	{
		playerPaddle.mPaddlePositions.y -= mPaddleSpeed * 3;
	}
	else if (playerPaddle.mPaddlePositions.y < 600 && mPlayerMove == -1)
	{
		playerPaddle.mPaddlePositions.y += mPaddleSpeed * 3;
	}

	mPlayerMove = 0;

	pongBall.Update();

	rRectPlayer = { playerPaddle.mPaddlePositions, playerPaddle.mPaddleDimension };
	rRectAi = { aiPaddle.mPaddlePositions, aiPaddle.mPaddleDimension };
	rBall = { {pongBall.mBallCenter},{pongBall.mBallRadius,pongBall.mBallRadius} };
}

void Pong::Render()
{
	//Rectangle rRect = { {700,300},{35,200} };

	Rectangle rBox = { {380,380},{40,40} };
	if (rBox.RectCollide(rBall) == false) {
		mRenderer->DrawRect(rBox);
	}
	mRenderer->DrawRect(rRectPlayer);
	mRenderer->DrawRect(rRectAi);
	mRenderer->DrawRect(rBall);
}

void Pong::OnInput(SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_UP)
	{
		mPlayerMove = 1;
	}
	else if (event.key.keysym.sym == SDLK_DOWN)
	{
		mPlayerMove = -1;
	}
	if (event.key.keysym.sym == SDLK_SPACE)
	{
		pongBall.mBallLunch = true;
	}
}

void Pong::Close()
{
}
