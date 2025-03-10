#include "Mesh.h"
#include "Asset.h"

Mesh::Mesh() : mVao(nullptr)
{
	//mVao = new VertexArray(cubeVertices, 28, cubeIndices, 36);
	mVertexShader.Load("BasicVert.shader", ShaderType::VERTEX);
	mFragmentShader.Load("BasicFrag.shader", ShaderType::FRAGMENT);
	mShaderProgram.Compose({ &mVertexShader, &mFragmentShader });
	mTexturesList.emplace_back(&Asset::GetTexture("yes"));
}

Mesh::Mesh(std::vector<Vertex> pVertices) : mVertices(std::move(pVertices)),mVao(nullptr)
{
	mVao = new VertexArray(ToVerticeArray(), mVertices.size());
	mVertexShader.Load("BasicVert.shader", ShaderType::VERTEX);
	mFragmentShader.Load("BasicFrag.shader", ShaderType::FRAGMENT);
	mShaderProgram.Compose({ &mVertexShader, &mFragmentShader });
	//mTexturesList.emplace_back(&Asset::GetTexture("yes"));
}

Mesh::~Mesh()
{
	Unload();
}

float* Mesh::ToVerticeArray()
{
	float* array = new float[mVertices.size() * 8];
	int counter = 0;
	for (int i = 0; i < mVertices.size(); i++)
	{
		array[counter + 0] = mVertices[i].position.x;
		array[counter + 1] = mVertices[i].position.y;
		array[counter + 2] = mVertices[i].position.z;
		array[counter + 3] = mVertices[i].normal.x;
		array[counter + 4] = mVertices[i].normal.y;
		array[counter + 5] = mVertices[i].normal.z;
		array[counter + 6] = mVertices[i].texCoord.x;
		array[counter + 7] = mVertices[i].texCoord.y;
		counter += 8;
	}
	return array;
}


void Mesh::Unload()
{
	//delete mVao;
	mVao = nullptr;
}

void Mesh::AddTexture(Texture* pTexture)
{
	mTexturesList.emplace_back(pTexture);
}