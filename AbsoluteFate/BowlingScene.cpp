#include "BowlingScene.h"
#include "RendererGl.h"

#include "Log.h"

void BowlingScene::SetRenderer(IRenderer* pRenderer)
{
	mRenderer = pRenderer;
}

void BowlingScene::Start()
{
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

	bowlingBallA = new BowlingBallA();
	bowlingBallA->AttachScene(this);
	AddActor(bowlingBallA);

	cubeTestA = new CubeTestA();
	cubeTestA->AttachScene(this);
	AddActor(cubeTestA);

	planeTextureOpenGlA = new PlaneTextureOpenGlA();
	planeTextureOpenGlA->AttachScene(this);
	AddActor(planeTextureOpenGlA);

	Scene::Start();
	sphereTestA->SetPosition(Vector3(0, 4, 0));
	bowlingBallA->SetPosition(Vector3(-20, 4, 0));
}

void BowlingScene::Update()
{
	Scene::Update();
	planeTextureOpenGlA->SetRotation2D(Maths::ToRad( bowlingBallA->GetStartRotation()));
}

void BowlingScene::Render()
{
	Scene::Render();
}

void BowlingScene::Close()
{
}
