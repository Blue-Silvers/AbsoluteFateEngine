#include "Texture.h"
#include "RendererSDL.h"

const Texture Texture::Default = {};

Texture::Texture() : mFilepathString(""),
					mSdlTexture(nullptr),
					mTextureWidth(1),
					mTextureHeight(1)
{
}

bool Texture::LoadTexture(IRenderer* pRenderer, const string& filename)
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

	IRenderer* test = pRenderer;
	//Create texture from surface
	if (RendererSDL* pRendererSDL = dynamic_cast<RendererSDL*>(test))
	{
		mSdlTexture = SDL_CreateTextureFromSurface(pRendererSDL->GetSdlRenderer(), surface); // get mSdlRenderer to Renderer	
	}

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
