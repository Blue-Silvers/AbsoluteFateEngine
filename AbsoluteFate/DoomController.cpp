#include "DoomController.h"
#include "IRenderer.h"
#include "InputManager.h"
#include "Actor.h"
#include "DoomPlayerA.h"
#include "Log.h"
#include <sstream>

DoomController::DoomController(Actor* pActor) : DoomMovingC(pActor)
{
	InputManager::Instance().SubscribeTo(SDLK_UP, this);
	InputManager::Instance().SubscribeTo(SDLK_DOWN, this);
	InputManager::Instance().SubscribeTo(SDLK_RIGHT, this);
	InputManager::Instance().SubscribeTo(SDLK_LEFT, this);

	InputManager::Instance().SubscribeTo(SDLK_z, this);
	InputManager::Instance().SubscribeTo(SDLK_s, this);
	InputManager::Instance().SubscribeTo(SDLK_d, this);
	InputManager::Instance().SubscribeTo(SDLK_q, this);

	InputManager::Instance().SubscribeTo(SDLK_ESCAPE, this);
	InputManager::Instance().SubscribeTo(SDLK_RETURN, this);

	InputManager::Instance().SubscribeTo(SDLK_SPACE, this);

	SDL_SetRelativeMouseMode(SDL_TRUE);

	//debug
	InputManager::Instance().SubscribeTo(SDLK_TAB, this);
}

void DoomController::OnNotify(SDL_Event& pEvent)
{
	switch (pEvent.type)
	{
	case SDL_KEYDOWN:

		switch (pEvent.key.keysym.sym)
		{
			//Directionnal input
		case SDLK_UP:
			SetSpeed(Vector3{ mMoveSpeed, 0, 0 });
			if (DoomPlayerA* doomPlayer = dynamic_cast<DoomPlayerA*>(mOwner))
			{
				doomPlayer->WalkAnim();
				
			}
			break;
		case SDLK_DOWN:
			SetSpeed(Vector3{ -mMoveSpeed, 0, 0 });
			if (DoomPlayerA* doomPlayer = dynamic_cast<DoomPlayerA*>(mOwner))
			{
				doomPlayer->WalkAnim();
			}
			break;
		case SDLK_RIGHT:
			SetSpeed(Vector3{ 0, mMoveSpeed, 0 });
			if (DoomPlayerA* doomPlayer = dynamic_cast<DoomPlayerA*>(mOwner))
			{
				doomPlayer->WalkAnim();
			}
			break;
		case SDLK_LEFT:
			SetSpeed(Vector3{ 0, -mMoveSpeed, 0 });
			if (DoomPlayerA* doomPlayer = dynamic_cast<DoomPlayerA*>(mOwner))
			{
				doomPlayer->WalkAnim();
			}
			break;
			//keyboard input
		case SDLK_z:
			SetSpeed(Vector3{ mMoveSpeed, 0, 0 });
			if (DoomPlayerA* doomPlayer = dynamic_cast<DoomPlayerA*>(mOwner))
			{
				doomPlayer->WalkAnim();
			}
			break;
		case SDLK_s:
			SetSpeed(Vector3{ -mMoveSpeed, 0, 0 });
			if (DoomPlayerA* doomPlayer = dynamic_cast<DoomPlayerA*>(mOwner))
			{
				doomPlayer->WalkAnim();
			}
			break;
		case SDLK_d:
			SetSpeed(Vector3{ 0, mMoveSpeed, 0 });
			if (DoomPlayerA* doomPlayer = dynamic_cast<DoomPlayerA*>(mOwner))
			{
				doomPlayer->WalkAnim();
			}
			break;
		case SDLK_q:
			SetSpeed(Vector3{ 0, -mMoveSpeed, 0 });
			if (DoomPlayerA* doomPlayer = dynamic_cast<DoomPlayerA*>(mOwner))
			{
				doomPlayer->WalkAnim();
			}
			break;
			//Flip flop show mouse cursor
		case SDLK_RETURN:
			if (SDL_GetRelativeMouseMode() == SDL_TRUE)
			{
				SDL_SetRelativeMouseMode(SDL_FALSE);
			}
			else
			{
				SDL_SetRelativeMouseMode(SDL_TRUE);
			}
			break;
		case SDLK_ESCAPE:
			if (SDL_GetRelativeMouseMode() == SDL_TRUE)
			{
				SDL_SetRelativeMouseMode(SDL_FALSE);
			}
			else
			{
				SDL_SetRelativeMouseMode(SDL_TRUE);
			}
			break;
		case SDLK_SPACE:
			//Shoot
			if (DoomPlayerA* doomPlayer = dynamic_cast<DoomPlayerA*>(mOwner))
			{
				doomPlayer->Shoot();
			}
			break;
		/*case SDLK_TAB:
			if (wireframe)
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				wireframe = !wireframe;
				Log::Info(" Debug mode : On");
			}
			else
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				wireframe = !wireframe;
				Log::Info(" Debug mode : Off");
			}
			break;*/
		default:

			break;
		}
		break;

	case SDL_KEYUP:

		SetSpeed(Vector3{ 0, 0, 0 });
		if (DoomPlayerA* doomPlayer = dynamic_cast<DoomPlayerA*>(mOwner))
		{
			doomPlayer->IdleAnim();
		}

		break;
	default:
		break;
	}
}
