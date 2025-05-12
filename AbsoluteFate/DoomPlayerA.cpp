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
	mCanVerticalMove = false;

	SetPosition(Vector3{ -30,0,0 });
	//move component
	DoomController* movement = new DoomController(this);
	movement->SetSpeed(Vector3{ 0, 0, 0 });
	AddComponent(movement);
}

void DoomPlayerA::Update()
{
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
	Vector3 startPoint = GetTransform().GetPosition();
	Vector3 endPoint = startPoint + GetTransform().GetWorldTransform().GetXAxis() * mShootRange;
	//Récupérer tout les acteurs collide entre le start et l'end et comparer leur distance du start, garder uniquement le plus proche et regarder si c'est un ennemy
	Log::Info(to_string(endPoint.x) + " | " + to_string(endPoint.y));
}
