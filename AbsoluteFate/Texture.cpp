#include "Texture.h"

bool Texture::LoadTexture(Renderer& pRenderer, const string& filename)
{
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
