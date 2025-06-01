#include "PlayerController.h"

#include "InputManager.h"
#include "Actor.h"
#include "Asset.h"
#include "AnimatedSpriteC.h"

#include <sstream>

PlayerController::PlayerController(Actor* pActor) : MovingC(pActor), mMoveSpeed(50)
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
			SetSpeed(Vector3{ 0, 0, mMoveSpeed });
			break;
		case SDLK_DOWN:
			SetSpeed(Vector3{ 0, 0, -mMoveSpeed });
			break;
		case SDLK_RIGHT:
			SetSpeed(Vector3{ 0, mMoveSpeed, 0 });
			break;
		case SDLK_LEFT:
			SetSpeed(Vector3{ 0, -mMoveSpeed, 0 });
			break;
		default:

			break;
		}
		break;
	case SDL_KEYUP:

		SetSpeed(Vector3{ 0, 0, 0 });
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