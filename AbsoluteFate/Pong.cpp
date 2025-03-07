#include "Pong.h"

#include "SpriteC.h"
#include "AnimatedSpriteC.h"
#include "MovingC.h"
#include "Asset.h"
#include "Actor.h"

void Pong::SetRenderer(IRenderer* pRenderer)
{
	mRenderer = pRenderer;
}

//Initialize scene
void Pong::Start()
{
	//Reset score
	mPoint[0] = 0;
	mPoint[1] = 0;
	//Reset position
	aiPaddle.mPaddlePositions = { 65,300 };
	playerPaddle.mPaddlePositions = { 700,300 };
	pongBall.Start(playerPaddle, aiPaddle);

		//Actor
	Asset::LoadAllTextureFromFolder(*mRenderer, "Ressources/Anim/DeathAngel/Idle/FrontIdle", "FrontIdle");
	Asset::LoadAllTextureFromFolder(*mRenderer, "Ressources/Anim/DeathAngel/Walk/FrontWalk", "FrontWalk");
	Asset::LoadAllTextureFromFolder(*mRenderer, "Ressources/Anim/DeathAngel/Walk/BackWalk", "BackWalk");
	Asset::LoadAllTextureFromFolder(*mRenderer, "Ressources/Anim/DeathAngel/Walk/LeftWalk", "LeftWalk");
	Asset::LoadAllTextureFromFolder(*mRenderer, "Ressources/Anim/DeathAngel/Walk/RightWalk", "RightWalk");
	DeathAngelA* actor = new DeathAngelA();
	actor->AttachScene(this);
	actor->SetScale2D(Vector2{ 1, 1 });
	AnimatedSpriteC* animation = new AnimatedSpriteC(actor, Asset::GetAnimation("FrontIdle"));
	animation->SetAnimationFps(10);
	actor->SetPosition2D(Vector2{ 500, 500 });
	actor->AddComponent(animation);

	MovingC* movement = new MovingC(actor);
	movement->SetSpeed(Vector3{0, 10, 0 });
	actor->AddComponent(movement);

	AddActor(actor);

	for (Actor* actor : mActorsList)
	{
		actor->Start();
	}
}

//Lunch new round
void Pong::Restart()
{
	aiPaddle.mPaddlePositions = { 65,300 };
	playerPaddle.mPaddlePositions = { 700,300 };
	pongBall.Start(playerPaddle, aiPaddle);

	for (Actor* actor : mActorsList)
	{
		actor->Start();
	}
}

void Pong::Update()
{
	mUpdatingActors = true;
	for (Actor* actor : mActorsList)
	{
		actor->Update();
	}
	mUpdatingActors = false;

	// Add pending actors to the pool
	for (Actor* actor : mActorsPending)
	{
		mActorsList.emplace_back(actor);
	}
	mActorsPending.clear();
	for (Actor* deadActor : mDeadActors)
	{
		delete deadActor;
	}



	if (pongBall.mBallAlive == false)
	{
		//Check which player to win
		if (pongBall.mBallCenter.x >= 800 - pongBall.mBallRadius / 2 || pongBall.mBallCenter.x <= pongBall.mBallRadius / 2)
		{
			mPoint[0] += 1; //Ai win
		}
		else if(pongBall.mBallCenter.x <= pongBall.mBallRadius / 2)
		{
			mPoint[1] += 1; //Player win
		}
		Restart(); // new round
	}

	//Move ai paddle, following ball and can't go out of the screen
	if (aiPaddle.mPaddlePositions.y > 0 && pongBall.mBallCenter.y < aiPaddle.mPaddlePositions.y + aiPaddle.mPaddleDimension.y/3)
	{
		aiPaddle.mPaddlePositions.y -= mPaddleSpeed; //Up
	}
	else if (aiPaddle.mPaddlePositions.y < 600 && pongBall.mBallCenter.y > aiPaddle.mPaddlePositions.y + (aiPaddle.mPaddleDimension.y / 3)*2)
	{
		aiPaddle.mPaddlePositions.y += mPaddleSpeed; //Down
	}

	//Move player paddle whith input key down and can't go out of the screen
	if (playerPaddle.mPaddlePositions.y > 0 && mPlayerMove == BigBool::TRUE)
	{
		playerPaddle.mPaddlePositions.y -= mPaddleSpeed * 3; //Up
	}
	else if (playerPaddle.mPaddlePositions.y < 600 && mPlayerMove == BigBool::FALSE)
	{
		playerPaddle.mPaddlePositions.y += mPaddleSpeed * 3; //Down
	}

	mPlayerMove = BigBool::MAYBE;
	//Update ball
	pongBall.Update();

	//Actualise drawing value
	rRectPlayer = { playerPaddle.mPaddlePositions, playerPaddle.mPaddleDimension };
	rRectAi = { aiPaddle.mPaddlePositions, aiPaddle.mPaddleDimension };
	rBall = { {pongBall.mBallCenter},{pongBall.mBallRadius,pongBall.mBallRadius} };
}


//Drawing
void Pong::Render()
{
	//Square in middle of the screen and disappear only if ball is in collider zone
	Rectangle rBox = { {380,380},{40,40} };
	if (RendererSDL* pRendererSDL = dynamic_cast<RendererSDL*>(mRenderer))
	{
		if (rBox.RectCollide(rBall) == false)
		{
			pRendererSDL->DrawRect(rBox);
		}

		//Draw paddles and ball
		pRendererSDL->DrawRect(rRectPlayer);
		pRendererSDL->DrawRect(rRectAi);
		pRendererSDL->DrawRectColor(rBall, redBall);
	}


	for (Actor* actor : mActorsList)
	{
		actor->Render();
	}
}

void Pong::Close()
{
}
