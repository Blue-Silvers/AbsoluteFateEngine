#include "GlTestScene.h"
#include "RendererGl.h"
#include "PlaneTextureOpenGlA.h"
#include "DeathAngelA.h"
#include "CubeTestA.h"

void GlTestScene::SetRenderer(IRenderer* pRenderer)
{
	mRenderer = pRenderer;
}

void GlTestScene::Start()
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
	CubeTestA* cubeTestA = new CubeTestA();
	cubeTestA->AttachScene(this);
	AddActor(cubeTestA);

	PlaneTextureOpenGlA* planeTextureOpenGlA = new PlaneTextureOpenGlA();
	planeTextureOpenGlA->AttachScene(this);
	AddActor(planeTextureOpenGlA);

	DeathAngelA* actor = new DeathAngelA();
	actor->AttachScene(this);
	AddActor(actor);


	for (Actor* actor : mActorsList)
	{
		actor->Start();
	}

}

void GlTestScene::Update()
{
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
