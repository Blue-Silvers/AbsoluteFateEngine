#include "Pong.h"

void Pong::SetRenderer(Renderer* pRenderer)
{
	mRenderer = pRenderer;
}

void Pong::Start()
{
	aiPaddle.mPaddlePositions = { 65,300 };
}

void Pong::Update()
{
	if (aiPaddle.mPaddlePositions.y < 600 && aiPaddle.onTop == true) 
	{
		aiPaddle.mPaddlePositions.y += mPaddleSpeed;
	}
	else if (aiPaddle.mPaddlePositions.y > 0 && aiPaddle.onTop == false)
	{
		aiPaddle.mPaddlePositions.y -= mPaddleSpeed;
	}
	else if (aiPaddle.mPaddlePositions.y <= 0 && aiPaddle.onTop == false)
	{
		aiPaddle.onTop = true;
	}
	else
	{
		aiPaddle.onTop = false;
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
}

void Pong::Render()
{
	mRenderer->BeginDraw();

	//Rectangle rRect = { {700,300},{35,200} };
	Rectangle rRectPlayer = {playerPaddle.mPaddlePositions, playerPaddle.mPaddleDimension};
	Rectangle rRectAi = { aiPaddle.mPaddlePositions, aiPaddle.mPaddleDimension };
	mRenderer->DrawRect(rRectPlayer);
	mRenderer->DrawRect(rRectAi);

	mRenderer->EndDraw();
}

void Pong::OnInput(SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_UP)
	{
		/*if (playerPaddle.mPaddlePositions.y > 0 )
		{
			playerPaddle.mPaddlePositions.y -= mPaddleSpeed * 3;
		}*/
		mPlayerMove = 1;
	}
	else if (event.key.keysym.sym == SDLK_DOWN)
	{
		/*if (playerPaddle.mPaddlePositions.y < 600)
		{
			playerPaddle.mPaddlePositions.y += mPaddleSpeed * 3;
		}*/
		mPlayerMove = -1;
	}
}

void Pong::Close()
{
}
