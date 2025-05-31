#include "BeachScene.h"

#include "RendererGl.h"
#include "Log.h"

void BeachScene::SetRenderer(IRenderer* pRenderer)
{
	mRenderer = pRenderer;
}

void BeachScene::Start()
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

	mWave = new WaveA();
	mWave->AttachScene(this);
	AddActor(mWave);

	mWaveBack = new SecondWaveA();
	mWaveBack->AttachScene(this);
	AddActor(mWaveBack);

	mBeach = new BeachA();
	mBeach->AttachScene(this);
	AddActor(mBeach);

	Scene::Start();

	cam->GetMovementComponent()->SetMoveSpeed(25.0F);
}

void BeachScene::Update()
{
	Scene::Update();
}

//Drawing
void BeachScene::Render()
{
	Scene::Render();
}

void BeachScene::Close()
{
}
