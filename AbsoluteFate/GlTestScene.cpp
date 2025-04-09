#include "GlTestScene.h"
#include "RendererGl.h"

#include "Log.h"

void GlTestScene::SetRenderer(IRenderer* pRenderer)
{
	mRenderer = pRenderer;
}

void GlTestScene::Start()
{
	//Sprite shader
	mShaderProgram = new ShaderProgram();

	mVertexShader.Load("TransformVert.shader", ShaderType::VERTEX);
	mFragmentShader.Load("SpriteFrag.shader", ShaderType::FRAGMENT);

	mShaderProgram->Compose({ &mVertexShader , &mFragmentShader });

	if (RendererGl* renderer = dynamic_cast<RendererGl*>(mRenderer))
	{
		renderer->SetShaderProgram(mShaderProgram);
	}

	//Actor

	cam = new CameraA();
	cam->AttachScene(this);
	AddActor(cam);

	sphereTestA = new SphereTestA();
	sphereTestA->AttachScene(this);
	AddActor(sphereTestA);

	/*sphereTestA2 = new SphereTestA();
	sphereTestA2->AttachScene(this);
	AddActor(sphereTestA2);*/

	/*bowlingBallA = new BowlingBallA();
	bowlingBallA->AttachScene(this);
	AddActor(bowlingBallA);*/

	corridor = new Corridor();
	corridor->AttachScene(this);
	AddActor(corridor);

	cubeTestA = new CubeTestA();
	cubeTestA->AttachScene(this);
	AddActor(cubeTestA);

	planeTextureOpenGlA = new PlaneTextureOpenGlA();
	planeTextureOpenGlA->AttachScene(this);
	AddActor(planeTextureOpenGlA);

	Scene::Start();
	sphereTestA->SetPosition(Vector3(0, 4, 0));
	//bowlingBallA->SetPosition(Vector3(-20, 4, 0));
}

void GlTestScene::Update()
{
	//if (sphereTestA2->GetBoxCollider()->OnCollide() != true)
	//{
	//	Vector3 newPosition = sphereTestA2->GetTransform().GetPosition() + Vector3::negUnitY * 0.05;
	//	sphereTestA2->SetPosition(newPosition);
	//}
	//else
	//{
	//	Log::Info("" + std::to_string(sphereTestA2->GetBoxCollider()->GetDistance().x) + ", " + std::to_string(sphereTestA2->GetBoxCollider()->GetDistance().y) + ", " + std::to_string(sphereTestA2->GetBoxCollider()->GetDistance().z));
	//}
	Scene::Update();
}

//Drawing
void GlTestScene::Render()
{
	Scene::Render();
}

void GlTestScene::Close()
{
}
