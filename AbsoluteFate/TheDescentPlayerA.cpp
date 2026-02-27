#include "TheDescentPlayerA.h"

#include "IRenderer.h"
#include "TheDescentController.h"
#include "Time.h"
#include "DoomLever.h"
#include "TheDescentScene.h"

#include "Log.h"

void TheDescentPlayerA::SetSensitivity(float pSensi)
{
	mSensitivity = pSensi;
}

float TheDescentPlayerA::GetSensitivity()
{
	return mSensitivity;
}

void TheDescentPlayerA::Start()
{
	mBoxCollider = new DoomBoxCollider3DC(this);
	mBoxCollider->SetCustomSize(Vector3(5, 1, 1));
	AddComponent(mBoxCollider);

	mCanVerticalMove = true;

	SetPosition(Vector3{ -30,0,0 });
	//move component
	TheDescentController* movement = new TheDescentController(this);
	movement->SetSpeed(Vector3{ 0, 0, 0 });
	AddComponent(movement);

	mHud = new DoomHudA;
	mHud->AttachScene(mSceneAttached);

	mHud->Start();

	mGun = new DoomGunA;
	mGun->AttachScene(mSceneAttached);

	mGun->Start();
}

void TheDescentPlayerA::Update()
{
	//Shoot
	if (mCanShootAgain == false)
	{
		mActualShootCooldown -= 1;
		//change animation
		if (mAnimState != DoomAnimState::Shoot)
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
	if (mSetHud == false)
	{
		mSceneAttached->AddActor(mHud);
		mSceneAttached->AddActor(mGun);
		mSetHud = true;
	}

	//Movement
	for (Components* component : mComponentsList)
	{
		if (TheDescentController* movementComponent = dynamic_cast<TheDescentController*>(component))
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

	//if ((mMouseDeltaX != 0 && SDL_GetRelativeMouseMode() == SDL_TRUE && mCanHorizontalMove == true) || (mMouseDeltaY != 0 && SDL_GetRelativeMouseMode() == SDL_TRUE && mCanVerticalMove == true))
	//{
	//	
	//	//Rotation is stocked in a vector before being transformed to quat via ZYX order
	//	const float pitch = mMouseDeltaY * mSensitivity;
	//	const float yaw = mMouseDeltaX * mSensitivity;

	//	mTransform.addRotationZ(yaw);
	//	mTransform.addRotationY(pitch);
	//	mTransform.clampRotationY(-89.0f, 89.0f);
	//	mTransform.computeRotation();
	//	Log::Info(to_string(yaw) + " | " + to_string(pitch));
	//}

	Matrix4Row view = Matrix4Row::CreateLookAt(camPosition, target, up);
	if (GetScene()->GetRenderer()->GetType() == IRenderer::RendererType::OPENGL)
	{
		GetScene()->GetRenderer()->SetViewMatrix(view);
	}
}

void TheDescentPlayerA::Destroy()
{
}

void TheDescentPlayerA::Shoot()
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
			DoomHitCollider breakHitCollider = mBoxCollider->GetOnCollideByLineTrace(startPoint + lineTraceDirection * i);
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

void TheDescentPlayerA::Interact()
{
	for (Components* component : GetAllComponent())
	{
		if (DoomBoxCollider3DC* boxCollider = dynamic_cast<DoomBoxCollider3DC*>(component))
		{
			DoomHitCollider breakHitCollider = boxCollider->GetOnCollide();
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

void TheDescentPlayerA::TakeDamage()
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
		if (TheDescentScene* theDescentScene = dynamic_cast<TheDescentScene*>(mSceneAttached))
		{
			theDescentScene->Retart();
		}
	}
	else
	{
		mHud->GetIconList()[lifePoint]->SetPosition2D(Vector2{ 0, 500 });
	}

}

void TheDescentPlayerA::WalkAnim()
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

void TheDescentPlayerA::IdleAnim()
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
