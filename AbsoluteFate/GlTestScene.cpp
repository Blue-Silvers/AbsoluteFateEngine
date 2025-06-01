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