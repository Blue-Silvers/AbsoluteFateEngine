#include "BowlingControllerC.h"

#include "BowlingBallA.h"
#include "Asset.h"
#include "InputManager.h"
#include "Actor.h"
#include "Log.h"
#include <sstream>

BowlingControllerC::BowlingControllerC(Actor* pActor) : Components(pActor)
{
	InputManager::Instance().SubscribeTo(SDLK_1, this);
	InputManager::Instance().SubscribeTo(SDLK_2, this);
	InputManager::Instance().SubscribeTo(SDLK_3, this);
	InputManager::Instance().SubscribeTo(SDLK_4, this);
	InputManager::Instance().SubscribeTo(SDLK_5, this);
	InputManager::Instance().SubscribeTo(SDLK_6, this);

	InputManager::Instance().SubscribeTo(SDLK_SPACE, this);
}

void BowlingControllerC::OnNotify(SDL_Event& pEvent)
{
	switch (pEvent.type)
	{
	case SDL_KEYDOWN:

		switch (pEvent.key.keysym.sym)
		{
		case SDLK_1:
			if (BowlingBallA* bowling = dynamic_cast<BowlingBallA*>(mOwner))
			{
				if (bowling->GetIsLunch() == false)
				{
					bowling->GetMeshC()->SetMesh(Asset::GetMesh("sphereSkin1"));
					bowling->GetMeshC()->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("Skin1")});
				}
			}
			break;
		case SDLK_2:
			if (BowlingBallA* bowling = dynamic_cast<BowlingBallA*>(mOwner))
			{
				if (bowling->GetIsLunch() == false)
				{
					bowling->GetMeshC()->SetMesh(Asset::GetMesh("sphereSkin2"));
					bowling->GetMeshC()->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("Skin2")});
				}
			}
			break;
		case SDLK_3:
			if (BowlingBallA* bowling = dynamic_cast<BowlingBallA*>(mOwner))
			{
				if (bowling->GetIsLunch() == false)
				{
					bowling->GetMeshC()->SetMesh(Asset::GetMesh("sphereSkin3"));
					bowling->GetMeshC()->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("Skin3")});
				}
			}
			break;
		case SDLK_4:
			if (BowlingBallA* bowling = dynamic_cast<BowlingBallA*>(mOwner))
			{
				if (bowling->GetIsLunch() == false)
				{
					bowling->GetMeshC()->SetMesh(Asset::GetMesh("sphereSkin4"));
					bowling->GetMeshC()->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("Skin4")});
				}
			}
			break;
		case SDLK_5:
			if (BowlingBallA* bowling = dynamic_cast<BowlingBallA*>(mOwner))
			{
				if (bowling->GetIsLunch()==false)
				{
					bowling->GetMeshC()->SetMesh(Asset::GetMesh("sphereSkin5"));
					bowling->GetMeshC()->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("Skin5")});
				}
			}
			break;
		case SDLK_6:
			if (BowlingBallA* bowling = dynamic_cast<BowlingBallA*>(mOwner))
			{
				if (bowling->GetIsLunch() == false)
				{
					bowling->GetMeshC()->SetMesh(Asset::GetMesh("sphereSkin6"));
					bowling->GetMeshC()->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("Skin6")});
				}
			}
			break;
			//Lunch
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
