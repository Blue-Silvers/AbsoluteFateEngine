#include "BowlingControllerC.h"

#include "BowlingBallA.h"
#include "InputManager.h"
#include "Actor.h"
#include "Log.h"
#include <sstream>

BowlingControllerC::BowlingControllerC(Actor* pActor) : Components(pActor)
{
	InputManager::Instance().SubscribeTo(SDLK_SPACE, this);
}

void BowlingControllerC::OnNotify(SDL_Event& pEvent)
{
	switch (pEvent.type)
	{
	case SDL_KEYDOWN:

		switch (pEvent.key.keysym.sym)
		{
			//Directionnal input
		case SDLK_SPACE:
			if (BowlingBallA* bowling = dynamic_cast<BowlingBallA*>(mOwner))
			{
				bowling->LunchBall();
			}
			break;

		default:
			break;
		}
		break;

	case SDL_KEYUP:

		
		break;
	default:
		break;
	}
}
