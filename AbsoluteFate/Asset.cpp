#include "Asset.h"
#include "Log.h"
#include <sstream>
#include <filesystem>

map<string, Texture> Asset::mTexturesMap = {};
map<string, vector<Texture> > Asset::mAnimationMap = {};

Texture Asset::LoadTextureFromFile(IRenderer& pRenderer, const string& pFileName)
{
	Texture texture;
	texture.LoadTexture(&pRenderer, pFileName);
	return texture;
}

Texture Asset::LoadTexture(IRenderer& pRenderer, const string& pFileName, const string& pTextureName)
{
	mTexturesMap[pTextureName] = LoadTextureFromFile(pRenderer, pFileName);
	return mTexturesMap[pTextureName];
}

vector<Texture> Asset::LoadAllTextureFromFolder(IRenderer& pRenderer, const string& pFileName, const string& pAnimationName)
{
	filesystem::directory_iterator it(pFileName);

	for (const auto& entry : it) 
	{
		auto& filePath = entry.path();
		if (entry.is_directory()) 
		{
			continue;
		}
		Texture texture = LoadTexture(pRenderer, filePath.string(), filePath.filename().replace_extension().string());
		//mAnimationMap[pAnimationName].push_back(&texture);
		mAnimationMap[pAnimationName].push_back(texture);
	}

	return mAnimationMap[pAnimationName];
}

Texture& Asset::GetTexture(const string& pTextureName)
{
	if (mTexturesMap.find(pTextureName) == mTexturesMap.end()) 
	{
		ostringstream loadError;
		loadError << "Texture " << pTextureName << " doesn't exist in assets manageer\n";
		Log::Error(LogType::Application, loadError.str());
	}
	return mTexturesMap[pTextureName];
}

vector<Texture>& Asset::GetAnimation(const string& pAnimationName)
{
	if (mAnimationMap.find(pAnimationName) == mAnimationMap.end())
	{
		ostringstream loadError;
		loadError << "Animation " << pAnimationName << " doesn't exist in assets manageer\n";
		Log::Error(LogType::Application, loadError.str());
	}
	return  mAnimationMap[pAnimationName];
}

void Asset::ClearMap()
{
	for (auto iter : mTexturesMap)
	{
		iter.second.UnloadTexture();
	}
	mTexturesMap.clear();
}
