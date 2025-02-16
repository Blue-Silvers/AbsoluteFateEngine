#pragma once
#include "Texture.h"
#include <map>
#include <string>
using namespace std;

class Asset
{
private:
	Asset() = default;
	static Texture LoadTextureFromFile(Renderer& pRenderer, const string& pFileName);

public:
	static map<string, Texture> mTexturesMap;
	static Texture LoadTexture(Renderer& pRenderer, const string& pFileName, const string& pTextureName);
	static Texture& GetTexture(const string pTextureName);
	static void ClearMap();
};

