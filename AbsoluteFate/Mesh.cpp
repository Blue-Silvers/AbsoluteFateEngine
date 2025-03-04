#include "Mesh.h"
#include "Asset.h"

Mesh::Mesh() : mVao(nullptr)
{
	mShaderProgram = new ShaderProgram();
	mVao = new VertexArray(cubeVertices, 28, cubeIndices, 36);
	mVertexShader.Load("BasicVert.shader", ShaderType::VERTEX);
	mFragmentShader.Load("BasicFrag.shader", ShaderType::FRAGMENT);
	mShaderProgram->Compose({ &mVertexShader, &mFragmentShader });
	mTexturesList.emplace_back(&Asset::GetTexture("wall"));
}

Mesh::~Mesh()
{
	Unload();
}

void Mesh::Unload()
{
	delete mVao;
	mVao = nullptr;
}

void Mesh::AddTexture(Texture* pTexture)
{
	mTexturesList.emplace_back(pTexture);
}