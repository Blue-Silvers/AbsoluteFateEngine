#include "Asset.h"
#include "Log.h"
#include <sstream>

map<string, Texture> Asset::mTexturesMap = {};

Texture Asset::LoadTextureFromFile(Renderer& pRenderer, const string& pFileName)
{
	Texture texture;
	texture.LoadTexture(pRenderer, pFileName);
	return texture;
}

Texture Asset::LoadTexture(Renderer& pRenderer, const string& pFileName, const string& pTextureName)
{
	mTexturesMap[pTextureName] = LoadTextureFromFile(pRenderer, pFileName);
	return mTexturesMap[pTextureName];
}

Texture& Asset::GetTexture(const string pTextureName)
{
	if (mTexturesMap.find(pTextureName) == mTexturesMap.end()) 
	{
		ostringstream loadError;
		loadError << "Texture " << pTextureName << " doesn't exist in assets manageer\n";
		Log::Error(LogType::Application, loadError.str());
	}
	return mTexturesMap[pTextureName];
}

void Asset::ClearMap()
{
	for (auto iter : mTexturesMap)
	{
		iter.second.UnloadTexture();
	}
	mTexturesMap.clear();
}
