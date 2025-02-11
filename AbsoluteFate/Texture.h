#pragma once
#include "SDL_image.h"
#include "Renderer.h"
#include <iostream>
#include <vector>
using namespace std;

class Texture
{
private:
	const string mFilepathString;
	SDL_Texture* mSdlTexture;
	int mTextureWidth, mTextureHeight;

public:
	bool LoadTexture(Renderer& pRenderer, const string& filename);
	void UnloadTexture();
	void UpdateInfo(int& pIntInfoWidth, int& pIntInfoHeight); // Using references to get two informations out
	int GetWidth();
	int GetHeight();
	Vector2D GetSize();
	SDL_Texture* GetSdlTexture() { return mSdlTexture; };
};

