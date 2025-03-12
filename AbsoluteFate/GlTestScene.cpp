#include "GlTestScene.h"
#include "RendererGl.h"
#include "PlaneTextureOpenGlA.h"
#include "FPSCameraA.h"
#include "CubeTestA.h"
#include "SphereTestA.h"
#include "CameraA.h"

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
	/*CubeTestA* cubeTestA = new CubeTestA();
	cubeTestA->AttachScene(this);
	AddActor(cubeTestA);*/

	CameraA* cam = new CameraA();
	cam->AttachScene(this);
	AddActor(cam);

	SphereTestA* sphereTestA = new SphereTestA();
	sphereTestA->AttachScene(this);
	AddActor(sphereTestA);

	PlaneTextureOpenGlA* planeTextureOpenGlA = new PlaneTextureOpenGlA();
	planeTextureOpenGlA->AttachScene(this);
	AddActor(planeTextureOpenGlA);



	Scene::Start();
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
