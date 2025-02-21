#pragma once
#include "Texture.h"
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

public:
	//Storage for future References
	static map<string, Texture> mTexturesMap;
	static map<string, vector<Texture> > mAnimationMap;

	static Texture LoadTexture(IRenderer& pRenderer, const string& pFileName, const string& pTextureName);
	static vector<Texture> LoadAllTextureFromFolder(IRenderer& pRenderer, const string& pFileName, const string& pAnimationName);
	static Texture& GetTexture(const string& pTextureName);
	static vector<Texture>& GetAnimation(const string& pAnimationName);
	static void ClearMap();
};

