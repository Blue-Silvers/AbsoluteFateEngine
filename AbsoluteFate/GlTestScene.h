#pragma once
#include "Scene.h"
#include "ShaderProgram.h"
#include "Shader.h"
#include "VertexArray.h"

class GlTestScene : public Scene
{
private:
	Shader mVertexShader;
	Shader mFragmentShader;
	ShaderProgram* mShaderProgram;
	VertexArray mVertexArray;

public:

	GlTestScene() :Scene("OpenGl") {};
	void SetRenderer(IRenderer* pRenderer) override;
	void Start() override;
	void Update()override;
	void Render() override;
	void  Close() override;
};

