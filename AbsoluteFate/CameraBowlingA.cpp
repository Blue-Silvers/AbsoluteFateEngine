#include "CameraBowlingA.h"

#include "IRenderer.h"
#include "FPSController.h"
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

	/*text1 = gltCreateText();
	gltSetText(text1, "Hey");*/
}

void CameraBowlingA::Update()
{

}

void CameraBowlingA::Destroy()
{
}

void CameraBowlingA::Render()
{
	/*float* matrix;
	matrix = view.GetMatrix16();
	GLfloat GLview[16];
	for (int i = 0; i < 16; i++)
	{
		GLview[i] = matrix[i];
	}
	matrix = GetScene()->GetRenderer()->GetProj().GetMatrix16();
	GLfloat GLproj[16];
	for (int i = 0; i < 16; i++)
	{
		GLproj[i] = matrix[i];
	}

	gltBeginDraw();
	gltColor(1.0f, 1.0f, 1.0f, 1.0f);
	gltDrawText3D(text1, 100, 200, 0, 10, GLview, GLproj);
	gltEndDraw();*/
}
