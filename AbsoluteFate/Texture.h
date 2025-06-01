#pragma once
#include "SDL_image.h"
#include <iostream>

using namespace std;

class IRenderer;
class RendererSDL;
class RendererGl;

class Texture
{
private:
	string mFilepathString;
	SDL_Texture* mSdlTexture;
	int mTextureWidth = 1, mTextureHeight = 1;

	unsigned int mTextureId;

	//Loaders
	bool LoadSDL(RendererSDL* pRenderer, const string& pFileName, SDL_Surface* pSurface);
	bool LoadGL(RendererGl* pRenderer, const string& pFileName, SDL_Surface* pSurface, bool pMipmaps = true);

protected:
	static const Texture Default;

public:
	//Constructor
	Texture();
	~Texture() = default;

	//Loader
	bool LoadTexture(IRenderer* pRenderer, const string& pFileName); //filenam = "Ressources/imageName.png"
	void UnloadTexture();

	//Setters
	void SetActive() const;
	void UpdateInfo(int& pIntInfoWidth, int& pIntInfoHeight) const; // Using references to get two informations out

	//Getters
	int GetWidth() const;
	int GetHeight() const;
	SDL_Texture* GetSdlTexture() const { return mSdlTexture; };
};