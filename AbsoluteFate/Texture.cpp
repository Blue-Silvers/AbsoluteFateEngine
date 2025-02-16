#include "Texture.h"
#include "Renderer.h"

const Texture Texture::Default = {};

Texture::Texture() : mFilepathString(""),
					mSdlTexture(nullptr),
					mTextureWidth(1),
					mTextureHeight(1)
{
}

bool Texture::LoadTexture(Renderer& pRenderer, const string& filename)
{
	mFilepathString = filename;

	SDL_Surface* surface = IMG_Load(mFilepathString.c_str());
	if (!surface)
	{
		Log::Error(LogType::Application, "Failed to load texture file :" + mFilepathString);
		return false;
	}
	mTextureWidth = surface->w;
	mTextureHeight = surface->h;

	//Create texture from surface
	mSdlTexture = SDL_CreateTextureFromSurface(/**/pRenderer.GetSdlRenderer(), surface); // get mSdlRenderer to Renderer
	SDL_FreeSurface(surface);
	if (!mSdlTexture)
	{
		Log::Error(LogType::Render, "Failed to convert surface to texture :" + mFilepathString);
		return false;
	}
	Log::Info("Loaded texture : " + mFilepathString);

	return true;
}

void Texture::UnloadTexture()
{
	if (mSdlTexture) 
	{
		SDL_DestroyTexture(mSdlTexture);
	}
}

//return mTextureWidth and mTextureHeight to pIntInfoWidth and pIntInfoHeight
void Texture::UpdateInfo(int& pIntInfoWidth, int& pIntInfoHeight) const
{
	pIntInfoWidth = mTextureWidth;
	pIntInfoHeight = mTextureHeight;
}

int Texture::GetWidth() const
{
	return mTextureWidth;
}

int Texture::GetHeight() const
{
	return mTextureHeight;
}
