#pragma once
#include "VertexArray.h"
#include "Texture.h"
#include "ShaderProgram.h"

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
	Texture* mNoise = nullptr;
	Texture* mNormal = nullptr;
	VertexArray* mVao;
	Shader mVertexShader;
	Shader mFragmentShader;

	Shader mTessControlShader;
	Shader mTessEvaluationShader;

	ShaderProgram mShaderProgram;
	std::vector<Vertex> mVertices;

public:
	Mesh();
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
	Texture* GetNoiseTexture() { return mNoise; };
	Texture* GetNormalTexture() { return mNormal; };
	int GetVerticeCount() {
		return mVertices.size();
	}

	//Setters
	float* ToVerticeArray();

	void SetTextureList(std::vector<Texture*> pTextureList) 
	{
		mTexturesList = pTextureList;
	};
	void SetNoiseTexture(Texture* pTexture)
	{
		mNoise = pTexture;
	};
	void SetNormalTexture(Texture* pTexture)
	{
		mNormal = pTexture;
	};
	void SetVao(VertexArray* pVao) 
	{
		mVao = pVao;
	};
	void SetVertexShader(Shader pVertexShader)
	{
		mVertexShader = pVertexShader;
		mShaderProgram.Compose({ &mVertexShader, &mFragmentShader});
	};
	void SetFragmentShader(Shader pFragmentShader)
	{
		mFragmentShader = pFragmentShader;
		mShaderProgram.Compose({ &mVertexShader, &mFragmentShader});
	};
	void SetShaderProgram(ShaderProgram& pShaderProgram)
	{
		mShaderProgram = pShaderProgram;
	};
};

