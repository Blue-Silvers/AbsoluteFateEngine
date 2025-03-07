#include "CameraA.h"

#include "IRenderer.h"
#include "FPSController.h"

#include "Log.h"

void CameraA::Start()
{
	SetRotation(Quaternion{ 0,0,0,0 });
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
		//move->Update();
	}

	Vector3 camPosition = mTransform.GetPosition();
	Vector3 target = mTransform.GetPosition() + mTransform.Forward() * 100.0f;
	Vector3 up = Vector3::unitZ;
	//Log::Info("" + std::to_string(camPosition.x) + ", " + std::to_string(camPosition.y) + ", " + std::to_string(camPosition.z));

	Matrix4Row view = Matrix4Row::CreateLookAt(camPosition, target, up);
	//Matrix4Row::CreateLookAt(mTransform.GetPosition(), target, Vector3::unitZ);
	if (GetScene()->GetRenderer()->GetType() == IRenderer::RendererType::OPENGL)
	{
		GetScene()->GetRenderer()->SetViewMatrix(view);
	}
}

void CameraA::Destroy()
{
}
