#include "TheDescentScene.h"

#include "RendererGl.h"

#include "Log.h"

void TheDescentScene::SetRenderer(IRenderer* pRenderer)
{
	mRenderer = pRenderer;
}

void TheDescentScene::Start()
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

	mPlayer = new TheDescentPlayerA();
	mPlayer->AttachScene(this);
	AddActor(mPlayer);

	mLevel = new DoomLevel();
	mLevel->AttachScene(this);
	AddActor(mLevel);

	mDoor = new DoomDoor();
	mDoor->AttachScene(this);
	AddActor(mDoor);

	mLever = new DoomLever();
	mLever->AttachScene(this);
	mLever->SetDoorLinked(mDoor);
	AddActor(mLever);

	mEnemy01 = new DoomEnemyA();
	mEnemy01->AttachScene(this);
	mEnemy01->SetTarget(mPlayer);
	AddActor(mEnemy01);

	mEnemy02 = new DoomEnemyA();
	mEnemy02->AttachScene(this);
	mEnemy02->SetTarget(mPlayer);
	AddActor(mEnemy02);

	Scene::Start();

	mEnemy02->SetPosition(Vector3{ 20, 15, 0.5 });
}

void TheDescentScene::Retart()
{
	mDoor->Restart();
	mLever->Restart();
	mEnemy01->Restart();
	mEnemy02->Restart();
	mEnemy02->SetPosition(Vector3{ 20, 15, 0.5 });
}

void TheDescentScene::Update()
{

	Scene::Update();
}

//Drawing
void TheDescentScene::Render()
{
	Scene::Render();
}

void TheDescentScene::Close()
{
}
