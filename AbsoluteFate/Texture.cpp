#include "Texture.h"
#include "SDL_image.h"

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
	mSdlTexture = SDL_CreateTextureFromSurface(pRenderer.GetSdlRenderer(), surface); // get mSdlRenderer to Renderer
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
void Texture::UpdateInfo(int& pIntInfoWidth, int& pIntInfoHeight)
{
	pIntInfoWidth = mTextureWidth;
	pIntInfoHeight = mTextureHeight;
}

int Texture::GetWidth()
{
	return mTextureWidth;
}

int Texture::GetHeight()
{
	return mTextureHeight;
}

Vector2D Texture::GetSize()
{
	return Vector2D(mTextureHeight, mTextureHeight);
}
