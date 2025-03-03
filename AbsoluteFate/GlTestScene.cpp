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
	mVertexArray = VertexArray(0, 4);
}

void GlTestScene::Update()
{
}

//Drawing
void GlTestScene::Render()
{
	mVertexArray.SetActive();
	//glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

void GlTestScene::Close()
{
}
