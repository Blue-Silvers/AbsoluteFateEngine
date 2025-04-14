#include "DoomScene.h"

#include "RendererGl.h"

#include "Log.h"

void DoomScene::SetRenderer(IRenderer* pRenderer)
{
	mRenderer = pRenderer;
}

void DoomScene::Start()
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

	player = new DoomPlayerA();
	player->AttachScene(this);
	AddActor(player);

	corridor = new Corridor();
	corridor->AttachScene(this);
	AddActor(corridor);


	Scene::Start();
	corridor->SetPosition(Vector3{ 10, 0, -5 });
}

void DoomScene::Update()
{

	Scene::Update();
}

//Drawing
void DoomScene::Render()
{
	Scene::Render();
}

void DoomScene::Close()
{
}
