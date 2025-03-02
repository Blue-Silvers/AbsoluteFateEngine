#include "GlTestScene.h"
#include "RendererGl.h"

void GlTestScene::SetRenderer(IRenderer* pRenderer)
{
	mRenderer = pRenderer;
}

void GlTestScene::Start()
{
	mVertexShader.Load("SimpleVert.shader", ShaderType::VERTEX);
	mFragmentShader.Load("SimpleFrag.shader", ShaderType::FRAGMENT);

	if (RendererGl* renderer = dynamic_cast<RendererGl*>(mRenderer))
	{
		renderer->SetShaderProgram(mShaderProgram);
	}
}

void GlTestScene::Update()
{
}

//Drawing
void GlTestScene::Render()
{
}

void GlTestScene::Close()
{
}
