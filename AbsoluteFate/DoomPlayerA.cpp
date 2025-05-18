#include "DoomPlayerA.h"

#include "IRenderer.h"
#include "DoomController.h"
#include "Time.h"
#include "DoomLever.h"
#include "DoomScene.h"

#include "Log.h"

void DoomPlayerA::SetSensitivity(float pSensi)
{
	mSensitivity = pSensi;
}

float DoomPlayerA::GetSensitivity()
{
	return mSensitivity;
}

void DoomPlayerA::Start()
{
	mBoxCollider = new DoomBoxCollider3DC(this);
	mBoxCollider->SetCustomSize(Vector3(5, 1, 1));
	AddComponent(mBoxCollider);

	mCanVerticalMove = false;

	SetPosition(Vector3{ -30,0,0 });
	//move component
	DoomController* movement = new DoomController(this);
	movement->SetSpeed(Vector3{ 0, 0, 0 });
	AddComponent(movement);

	mHud = new DoomHudA;
	mHud->AttachScene(mSceneAttached);
	
	mHud->Start();

	mGun = new DoomGunA;
	mGun->AttachScene(mSceneAttached);

	mGun->Start();
}

void DoomPlayerA::Update()
{
	//Shoot
	if (mCanShootAgain == false) 
	{
		mActualShootCooldown -= 1;
		//change animation
		if(mAnimState != DoomAnimState::Shoot)
		{
			for (Components* moveAnim : mGun->GetAllComponent())
			{
				if (AnimatedSpriteC* anim = dynamic_cast<AnimatedSpriteC*>(moveAnim))
				{
					anim->SetAnimationTextures(Asset::GetAnimation("DoomShoot"));
					mAnimState = DoomAnimState::Shoot;
				}
			}
		}
		if (mActualShootCooldown <= 0) 
		{
			mCanShootAgain = true;
			//change animation
			for (Components* moveAnim : mGun->GetAllComponent())
			{
				if (AnimatedSpriteC* anim = dynamic_cast<AnimatedSpriteC*>(moveAnim))
				{
					anim->SetAnimationTextures(Asset::GetAnimation("DoomIdle"));
					mAnimState = DoomAnimState::Idle;
				}
			}
		}
	}

	//HUD
	if(mSetHud == false)
	{
		mSceneAttached->AddActor(mHud);
		mSceneAttached->AddActor(mGun);
		mSetHud = true;
	}

	//Movement
	for (Components* component : mComponentsList)
	{
		if (DoomController* movementComponent = dynamic_cast<DoomController*>(component))
		{
			movementComponent->Update();
		}
	}

	//ViewProj
	Vector3 camPosition = mTransform.GetPosition();
	Vector3 target = mTransform.GetPosition() + mTransform.Forward() * 400.0f;
	Vector3 up = Vector3::unitZ;

	SDL_GetRelativeMouseState(&mMouseDeltaX, &mMouseDeltaY);
	if (mMouseDeltaX != 0 && SDL_GetRelativeMouseMode() == SDL_TRUE && mCanHorizontalMove == true)
	{
		mTransform.RotateZInDegrees(mMouseDeltaX * mSensitivity);
	}
	if (mMouseDeltaY != 0 && SDL_GetRelativeMouseMode() == SDL_TRUE && mCanVerticalMove == true)
	{
		mTransform.RotateYInDegrees(mMouseDeltaY * mSensitivity);
	}

	Matrix4Row view = Matrix4Row::CreateLookAt(camPosition, target, up);
	if (GetScene()->GetRenderer()->GetType() == IRenderer::RendererType::OPENGL)
	{
		GetScene()->GetRenderer()->SetViewMatrix(view);
	}
}

void DoomPlayerA::Destroy()
{
}

void DoomPlayerA::Shoot()
{
	if (mCanShootAgain == true)
	{
		mCanShootAgain = false;
		mActualShootCooldown = mShootCooldown;

		//LINETRACE
		Vector3 startPoint = GetTransform().GetPosition();		
		Vector3 lineTraceDirection = GetTransform().GetWorldTransform().GetXAxis();
		Vector3 endPoint = startPoint + lineTraceDirection * mShootRange;
		for (int i = 1; i <= mShootRange; i++) 
		{
			HitCollider breakHitCollider = mBoxCollider->GetOnCollideByLineTrace(startPoint + lineTraceDirection * i);
			if (breakHitCollider.isCollid == true && breakHitCollider.isOverlap == false)
			{
				endPoint = startPoint + lineTraceDirection * i;
				if (DoomEnemyA* enemy = dynamic_cast<DoomEnemyA*>(breakHitCollider.collideActor))
				{
					enemy->TakeDamage();
				}
				break;
			}
		}
		//Log::Info(to_string(endPoint.x) + " | " + to_string(endPoint.y));
	}
}

void DoomPlayerA::Interact()
{
	for (Components* component : GetAllComponent())
	{
		if (DoomBoxCollider3DC* boxCollider = dynamic_cast<DoomBoxCollider3DC*>(component))
		{
			HitCollider breakHitCollider = boxCollider->GetOnCollide();
			if (breakHitCollider.isCollid == true)
			{
				for (Components* component : breakHitCollider.collideActor->GetAllComponent())
				{
					if (DoomBoxCollider3DC* boxCollider3DC = dynamic_cast<DoomBoxCollider3DC*>(component))
					{
						if (boxCollider3DC->GetIsOverlap() == true)
						{
							if (DoomLever* lever = dynamic_cast<DoomLever*>(breakHitCollider.collideActor))
							{
								lever->SetLeverActive(!lever->GetLeverActive());
							}
						}
					}
				}
			}
		}
	}
}

void DoomPlayerA::TakeDamage()
{
	//TakeDamage
	lifePoint -= 1;
	if (lifePoint == -1)
	{
		lifePoint = 3;
		SetPosition(Vector3{ -30,0,0 });
		SetRotation(Quaternion::Identity);
		mHud->Restart();

		//Restart scene
		if (DoomScene* doomScene = dynamic_cast<DoomScene*>(mSceneAttached))
		{
			doomScene->Retart();
		}
	}
	else
	{
		mHud->GetIconList()[lifePoint]->SetPosition2D(Vector2{ 0, 500 });
	}

}

void DoomPlayerA::WalkAnim()
{
	if (mCanShootAgain == true && mAnimState != DoomAnimState::Walk)
	{
		//change animation
		for (Components* moveAnim : mGun->GetAllComponent())
		{
			if (AnimatedSpriteC* anim = dynamic_cast<AnimatedSpriteC*>(moveAnim))
			{
				anim->SetAnimationTextures(Asset::GetAnimation("DoomWalk"));
				mAnimState = DoomAnimState::Walk;
			}
		}
	}
}

void DoomPlayerA::IdleAnim()
{
	if (mCanShootAgain == true && mAnimState != DoomAnimState::Idle)
	{
		//change animation
		for (Components* moveAnim : mGun->GetAllComponent())
		{
			if (AnimatedSpriteC* anim = dynamic_cast<AnimatedSpriteC*>(moveAnim))
			{
				anim->SetAnimationTextures(Asset::GetAnimation("DoomIdle"));
				mAnimState = DoomAnimState::Idle;
			}
		}
	}
}
