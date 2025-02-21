#include "PlayerController.h"
#include "InputManager.h"
#include "Actor.h"
#include "Asset.h"
#include "AnimatedSpriteC.h"

#include "Log.h"
#include <sstream>

PlayerController::PlayerController(Actor* pActor) : MovingC(pActor)
{
	InputManager::Instance().SubscribeTo(SDLK_UP, this);
	InputManager::Instance().SubscribeTo(SDLK_DOWN, this);
	InputManager::Instance().SubscribeTo(SDLK_RIGHT, this);
	InputManager::Instance().SubscribeTo(SDLK_LEFT, this);
}

void PlayerController::OnNotify(SDL_Event& pEvent)
{
	switch (pEvent.type)
	{
	case SDL_KEYDOWN:

		switch (pEvent.key.keysym.sym)
		{
		case SDLK_UP:
			SetSpeed(Vector2{ 0, 50 });
			break;
		case SDLK_DOWN:
			SetSpeed(Vector2{ 0, -50 });
			break;
		case SDLK_RIGHT:
			SetSpeed(Vector2{ 50, 0 });
			break;
		case SDLK_LEFT:
			SetSpeed(Vector2{ -50, 0 });
			break;
		default:

			break;
		}
		/*if (pEvent.key.keysym.sym == SDLK_UP)
		{
			SetSpeed(Vector2D{ 0, 50 });
		}
		else if (pEvent.key.keysym.sym == SDLK_DOWN)
		{
			SetSpeed(Vector2D{ 0, -50 });
		}
		else if (pEvent.key.keysym.sym == SDLK_RIGHT)
		{
			SetSpeed(Vector2D{ 50, 0 });
		}
		else if (pEvent.key.keysym.sym == SDLK_LEFT)
		{
			SetSpeed(Vector2D{ -50, 0 });
		}*/
		break;
	case SDL_KEYUP:

		SetSpeed(Vector2{ 0, 0 });
		break;
	default:
		break;
	}

			//change animation
	for (Components* moveAnim : mOwner->GetAllComponent())
	{
		if (AnimatedSpriteC* anim = dynamic_cast<AnimatedSpriteC*>(moveAnim))
		{
			if (mSpeed.x == 0 && mSpeed.y == 0)//Idle
			{
				switch (currentDirection)
				{
				case MOVE_UP:
					anim->SetAnimationTextures(Asset::GetAnimation("BackIdle"));
					currentDirection = MOVE_STOP;
					break;
				case MOVE_DOWN:
					anim->SetAnimationTextures(Asset::GetAnimation("FrontIdle"));
					currentDirection = MOVE_STOP;
					break;
				case MOVE_RIGHT:
					anim->SetAnimationTextures(Asset::GetAnimation("RightIdle"));
					currentDirection = MOVE_STOP;
					break;
				case MOVE_LEFT:
					anim->SetAnimationTextures(Asset::GetAnimation("LeftIdle"));
					currentDirection = MOVE_STOP;
					break;
				default:

					break;
				}
			}
			else if (currentDirection != lastDirection)//Walk
			{
				switch (currentDirection)
				{
				case MOVE_UP:
					anim->SetAnimationTextures(Asset::GetAnimation("BackWalk"));
					break;
				case MOVE_DOWN:
					anim->SetAnimationTextures(Asset::GetAnimation("FrontWalk"));
					break;
				case MOVE_RIGHT:
					anim->SetAnimationTextures(Asset::GetAnimation("RightWalk"));
					break;
				case MOVE_LEFT:
					anim->SetAnimationTextures(Asset::GetAnimation("LeftWalk"));
					break;
				default:

					break;
				}
			}
		}
	}
}