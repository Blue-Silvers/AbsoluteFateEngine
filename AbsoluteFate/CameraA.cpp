#include "CameraA.h"

#include "IRenderer.h"
#include "FPSController.h"
#include "Time.h"

#include "Log.h"

void CameraA::Start()
{
	SetRotation(Quaternion(0, 0, 0, 1));
	SetScale(Vector3{ 1, 1, 1 }); //scale
	SetPosition(Vector3{ -20,0,0 });
	//move component
	FPSController* movement = new FPSController(this);
	movement->SetSpeed(Vector3{ 0, 0, 0 });
	AddComponent(movement);
}

void CameraA::Update()
{
	for (Components* move : mComponentsList)
	{
		if (FPSController* movementComponent = dynamic_cast<FPSController*>(move))
		{
			movementComponent->Update();
		}
	}

	Vector3 camPosition = mTransform.GetPosition();
	Vector3 target = mTransform.GetPosition() + mTransform.Forward() * 400.0f;
	Vector3 up = Vector3::unitZ;
	//Log::Info("" + std::to_string(camPosition.x) + ", " + std::to_string(camPosition.y) + ", " + std::to_string(camPosition.z));
	SDL_GetRelativeMouseState(&mMouseDeltaX, &mMouseDeltaY);

					//don't work//
	if (mMouseDeltaX != 0) 
	{
		//Log::Info("" + std::to_string(mMouseDeltaX) + ", " + std::to_string(mMouseDeltaY));
		//mTransform.Rotate(1, Vector3::unitY);
		mTransform.RotateXInDegrees(mMouseDeltaX);
		mTransform.ComputeWorldTransform();
	}
	if (mMouseDeltaY != 0)
	{
		//Log::Info("" + std::to_string(mMouseDeltaX) + ", " + std::to_string(mMouseDeltaY));
		//mTransform.Rotate(1, Vector3::unitY);
		mTransform.RotateYInDegrees(mMouseDeltaY);
		mTransform.ComputeWorldTransform();
	}
	Log::Info("" + std::to_string(mTransform.GetRotation().x) + ", " + std::to_string(mTransform.GetRotation().y) + ", " + std::to_string(mTransform.GetRotation().z));
	//Log::Info("" + std::to_string(target.x) + ", " + std::to_string(target.y) + ", " + std::to_string(target.z));
					/////////////

	Matrix4Row view = Matrix4Row::CreateLookAt(camPosition, target, up);
	if (GetScene()->GetRenderer()->GetType() == IRenderer::RendererType::OPENGL)
	{
		GetScene()->GetRenderer()->SetViewMatrix(view);
	}
}

void CameraA::Destroy()
{
}
