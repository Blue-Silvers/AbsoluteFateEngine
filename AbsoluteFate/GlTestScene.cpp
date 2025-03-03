#include "GlTestScene.h"
#include "RendererGl.h"
#include "PlaneTextureOpenGlA.h"

void GlTestScene::SetRenderer(IRenderer* pRenderer)
{
	mRenderer = pRenderer;
}

void GlTestScene::Start()
{
	mShaderProgram = new ShaderProgram();

	mVertexShader.Load("SpriteVert.shader", ShaderType::VERTEX);
	mFragmentShader.Load("SpriteFrag.shader", ShaderType::FRAGMENT);

	mShaderProgram->Compose({ &mVertexShader , &mFragmentShader });

	if (RendererGl* renderer = dynamic_cast<RendererGl*>(mRenderer))
	{
		renderer->SetShaderProgram(mShaderProgram);
	}

	PlaneTextureOpenGlA* planeTextureOpenGlA = new PlaneTextureOpenGlA();
	planeTextureOpenGlA->AttachScene(this);

	AddActor(planeTextureOpenGlA);

	for (Actor* actor : mActorsList)
	{
		actor->Start();
	}

}

void GlTestScene::Update()
{
	mUpdatingActors = true;
	for (Actor* actor : mActorsList)
	{
		actor->Update();
	}
	mUpdatingActors = false;

	// Add pending actors to the pool
	for (Actor* actor : mActorsPending)
	{
		mActorsList.emplace_back(actor);
	}
	mActorsPending.clear();
	for (Actor* deadActor : mDeadActors)
	{
		delete deadActor;
	}
}

//Drawing
void GlTestScene::Render()
{
	
	for (Actor* actor : mActorsList)
	{
		actor->Render();
	}
}

void GlTestScene::Close()
{
}
