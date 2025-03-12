#pragma once
#define TINYOBJLOADER_IMPLEMENTATION

#include "Texture.h"
#include "Mesh.h"
#include <map>
#include <string>
#include <vector>

using namespace std;

//SINGLETON CLASS
class Asset
{
private:
	Asset() = default;
	static Texture LoadTextureFromFile(IRenderer& pRenderer, const string& pFileName);
	static Mesh LoadMeshFromFile(const string& pFileName);

public:
	//Storage for future References
	static map<string, Texture> mTexturesMap;
	static map<string, vector<Texture> > mAnimationMap;
	static map<string, Mesh> mMeshMap;

	static Texture LoadTexture(IRenderer& pRenderer, const string& pFileName, const string& pTextureName);
	static vector<Texture> LoadAllTextureFromFolder(IRenderer& pRenderer, const string& pFileName, const string& pAnimationName);
	//static Mesh LoadMeshFromFile(const string& pFileName);
	static Mesh LoadMesh(const string& pFileName, const string& pMeshName);
	static Mesh& GetMesh(const string& pMeshName);
	static Texture& GetTexture(const string& pTextureName);
	static vector<Texture>& GetAnimation(const string& pAnimationName);
	static void ClearMap();
};

