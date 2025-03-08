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

struct Vertex
{
	Vector3 position{ 0,0,0 };
	Vector3 normal{ 0,0,0 };
	Vector2 texCoord{ 0 ,0 };

};

class Mesh
{
private:
	std::vector<Texture*> mTexturesList;
	VertexArray* mVao;
	Shader mVertexShader;
	Shader mFragmentShader;
	ShaderProgram mShaderProgram;
	std::vector<Vertex> mVertices;

public:

	Mesh(std::vector<Vertex> pVertices);
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
	float* ToVerticeArray();

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

