#include "CameraBowlingA.h"

#include "IRenderer.h"
#include "Time.h"

#include "Log.h"


void CameraBowlingA::Start()
{
	SetPosition(Vector3{ -10,0,10 });
	mTransform.RotateYInDegrees(20);
	//Render
	Vector3 camPosition = mTransform.GetPosition();
	Vector3 target = mTransform.GetPosition() + mTransform.Forward() * 400.0f;
	Vector3 up = Vector3::unitZ;

	view = Matrix4Row::CreateLookAt(camPosition, target, up);
	if (GetScene()->GetRenderer()->GetType() == IRenderer::RendererType::OPENGL)
	{
		GetScene()->GetRenderer()->SetViewMatrix(view);
	}
}

void CameraBowlingA::Update()
{

}

void CameraBowlingA::Destroy()
{
}

void CameraBowlingA::Render()
{

}