#include "GlTestScene.h"
#include "RendererGl.h"

void GlTestScene::SetRenderer(IRenderer* pRenderer)
{
	mRenderer = pRenderer;
}

void GlTestScene::Start()
{
	mShaderProgram = new ShaderProgram();

	mVertexShader.Load("SimpleVert.shader", ShaderType::VERTEX);
	mFragmentShader.Load("SimpleFrag.shader", ShaderType::FRAGMENT);

	mShaderProgram->Compose({ &mVertexShader , &mFragmentShader });

	//mVertexArray = VertexArray(0, 4);
	//mVertexArray.SetActive();

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
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

void GlTestScene::Close()
{
}
