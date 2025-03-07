#pragma once
#include "VertexArray.h"
#include "Texture.h"
#include "ShaderProgram.h"

constexpr float cubeVertices[] = {
	//Coordonate:		  Uv pos: R/L   T/B
	-0.5f, -0.5f, -0.5f,		  0.0f, 0.0f,   // Front face
	 0.5f, -0.5f, -0.5f,		  1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,		  0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,		  1.0f, 1.0f,

	-0.5f, -0.5f,  0.5f,		  0.0f, 0.0f,   // Back face
	 0.5f, -0.5f,  0.5f,		  1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,		  0.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,		  1.0f, 1.0f,

	-0.5f, -0.5f, -0.5f,		  0.0f, 0.0f,   // Left face
	-0.5f, -0.5f,  0.5f,		  1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,		  0.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,		  1.0f, 1.0f,

	 0.5f, -0.5f, -0.5f,		  0.0f, 0.0f,   // Right face
	 0.5f, -0.5f,  0.5f,		  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,		  0.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,		  1.0f, 1.0f,

	-0.5f, -0.5f, -0.5f,		  0.0f, 0.0f,   // Bottom face
	 0.5f, -0.5f, -0.5f,		  1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,		  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,		  1.0f, 1.0f,

	-0.5f,  0.5f, -0.5f,		  0.0f, 0.0f,   // Top face
	 0.5f,  0.5f, -0.5f,		  1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,		  0.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,		  1.0f, 1.0f
};

constexpr unsigned int cubeIndices[] = {
   0, 2, 1,  1, 2, 3,		// Front face
   4, 5, 6,  5, 7, 6,		// Back face
   8, 9, 10, 9, 11, 10,		// Left face
   12, 13, 14, 13, 15, 14,	// Right face
   16, 17, 18, 17, 19, 18,	// Bottom face
   20, 21, 22, 21, 23, 22	// FTop face
};

class Mesh
{
private:
	std::vector<Texture*> mTexturesList;
	VertexArray* mVao;
	Shader mVertexShader;
	Shader mFragmentShader;
	ShaderProgram mShaderProgram;

public:

	Mesh();
	~Mesh();

	void Unload();
	void AddTexture(Texture* pTexture);

	//Getters
	std::vector<Texture*> GetAllFaceTexture() { return mTexturesList; }
	VertexArray* GetVao() { return mVao; }
	Shader GetVertexShader() { return mVertexShader; }
	Shader GetFragmentShader() { return mFragmentShader; }
	ShaderProgram& GetShaderProgram() { return mShaderProgram; }
	Texture* GetTexture(int pTextureIndex) { return mTexturesList[pTextureIndex]; };

	//Setters
	void SetTextureList(std::vector<Texture*> pTextureList) 
	{
		mTexturesList = pTextureList;
	};
	void SetVao(VertexArray* pVao) 
	{
		mVao = pVao;
	};
	void SetVertexShader(Shader pVertexShader)
	{
		mVertexShader = pVertexShader;
	};
	void SetFragmentShader(Shader pFragmentShader)
	{
		mFragmentShader = pFragmentShader;
	};
	void SetShaderProgram(ShaderProgram& pShaderProgram)
	{
		mShaderProgram = pShaderProgram;
	};
};

