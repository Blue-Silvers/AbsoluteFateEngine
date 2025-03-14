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

	cam = new CameraBowlingA();
	cam->AttachScene(this);
	AddActor(cam);

	bowlingHudA = new BowlingHudA();
	bowlingHudA->AttachScene(this);
	AddActor(bowlingHudA);

	bowlingUISkinA = new BowlingUISkinA();
	bowlingUISkinA->AttachScene(this);
	AddActor(bowlingUISkinA);

	bowlingBallA = new BowlingBallA();
	bowlingBallA->AttachScene(this);
	AddActor(bowlingBallA);

	setOfPinA = new SetOfPinA();
	setOfPinA->AttachScene(this);
	AddActor(setOfPinA);

	rightBorderA = new BowlingBorderA();
	rightBorderA->AttachScene(this);
	AddActor(rightBorderA);

	leftBorderA = new BowlingBorderA();
	leftBorderA->AttachScene(this);
	AddActor(leftBorderA);

	pathA = new BowlingPathA();
	pathA->AttachScene(this);
	AddActor(pathA);

	Scene::Start();

	rightBorderA->SetPosition(Vector3{ 15, 7, -2 }); //location
	leftBorderA->SetPosition(Vector3{ 15, -7, -2 }); //location
	bowlingBallA->SetPosition(Vector3(0, 0, 0));
}

void BowlingScene::Update()
{
	Scene::Update();
	if (bowlingBallA->GetIsLunch()==false)
	{
		bowlingHudA->SetRotation2D(Maths::ToRad(- bowlingBallA->GetStartRotation()));
	}
}

void BowlingScene::Render()
{
	Scene::Render();
}

void BowlingScene::Close()
{
}
