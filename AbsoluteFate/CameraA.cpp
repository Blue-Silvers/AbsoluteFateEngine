#include "CameraA.h"

#include "IRenderer.h"
#include "FPSController.h"

void CameraA::SetSensitivity(float pSensi)
{
	mSensitivity = pSensi;
}

float CameraA::GetSensitivity()
{
	return mSensitivity;
}

void CameraA::Start()
{
	mCanVerticalMove = false;

	SetPosition(Vector3{ -20,0,0 });
	//move component
	movement = new FPSController(this);
	movement->SetSpeed(Vector3{ 0, 0, 0 });
	AddComponent(movement);
}

void CameraA::Update()
{
	for (Components* component : mComponentsList)
	{
		if (FPSController* movementComponent = dynamic_cast<FPSController*>(component))
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

	Matrix4Row view = Matrix4Row::CreateLookAt(camPosition, target, up);
	if (GetScene()->GetRenderer()->GetType() == IRenderer::RendererType::OPENGL)
	{
		GetScene()->GetRenderer()->SetViewMatrix(view);
	}
}

void CameraA::Destroy()
{
}