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

void Pong::OnInput(SDL_Event)
{

}

void Pong::Close()
{
}
