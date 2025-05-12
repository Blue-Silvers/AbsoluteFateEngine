#include "DoomPlayerA.h"

#include "IRenderer.h"
#include "DoomController.h"
#include "Time.h"

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
	mBoxCollider = new BoxCollider3DC(this);
	mBoxCollider->SetCustomSize(Vector3(5, 5, 3));
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

	if(mSetHud == false)
	{
		mSceneAttached->AddActor(mHud);
		mSceneAttached->AddActor(mGun);
		mSetHud = true;
	}

	for (Components* component : mComponentsList)
	{
		if (DoomController* movementComponent = dynamic_cast<DoomController*>(component))
		{
			movementComponent->Update();
		}
	}

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
	//Log::Info("" + std::to_string(mTransform.GetRotation().x) + ", " + std::to_string(mTransform.GetRotation().y) + ", " + std::to_string(mTransform.GetRotation().z)); //DEBUG//

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

		Vector3 startPoint = GetTransform().GetPosition();
		Vector3 endPoint = startPoint + GetTransform().GetWorldTransform().GetXAxis() * mShootRange;
		//Récupérer tout les acteurs collide entre le start et l'end et comparer leur distance du start, garder uniquement le plus proche et regarder si c'est un ennemy
		Log::Info(to_string(endPoint.x) + " | " + to_string(endPoint.y));

		//TakeDammage
		/*lifePoint -= 1;
		mHud->GetIconList()[lifePoint]->SetPosition2D(Vector2{ 0, 500 });*/
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
