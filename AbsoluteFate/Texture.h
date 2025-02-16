#pragma once
#include "SDL_image.h"
//#include "Renderer.h"
#include <iostream>

using namespace std;

class Renderer;

class Texture
{
private:
	string mFilepathString;
	SDL_Texture* mSdlTexture;
	int mTextureWidth = 1, mTextureHeight = 1;

protected:
	static const Texture Default;

public:
	Texture();
	bool LoadTexture(Renderer& pRenderer, const string& filename); //filenam = "Picture/pokeball.png"
	void UnloadTexture();
	void UpdateInfo(int& pIntInfoWidth, int& pIntInfoHeight) const; // Using references to get two informations out
	int GetWidth() const;
	int GetHeight() const;
	SDL_Texture* GetSdlTexture() const { return mSdlTexture; };
};

