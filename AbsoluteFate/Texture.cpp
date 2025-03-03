#include "Texture.h"
#include "RendererSDL.h"
#include "RendererGl.h"

const Texture Texture::Default = {};

bool Texture::LoadSDL(RendererSDL* pRenderer, const string& pFileName, SDL_Surface* pSurface)
{
	//Create texture from surface
	mSdlTexture = SDL_CreateTextureFromSurface(pRenderer->GetSdlRenderer(), pSurface); // get mSdlRenderer to Renderer
	SDL_FreeSurface(pSurface);

	if (!mSdlTexture)
	{
		Log::Error(LogType::Render, "Failed to convert surface to texture :" + mFilepathString);
		return false;
	}
	Log::Info("Loaded texture : " + mFilepathString);

	return true;
}

bool Texture::LoadGL(RendererGl* pRenderer, const string& pFileName, SDL_Surface* pSurface)
{
	int format = 0;
	if (pSurface->format->format == SDL_PIXELFORMAT_RGB24) 
	{
		format = GL_RGB;
	}
	else if (pSurface->format->format == SDL_PIXELFORMAT_RGBA32)
	{
		format = GL_RGBA;
	}
	glGenTextures(1, &mTextureId);
	glBindTexture(GL_TEXTURE_2D, mTextureId);
	glTexImage2D(GL_TEXTURE_2D, 0, format, mTextureWidth, mTextureHeight, 0, format, GL_UNSIGNED_BYTE, pSurface->pixels);
	SDL_FreeSurface(pSurface);

	Log::Info("Loaded GL texture : " + mFilepathString);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	return true;
}

Texture::Texture() : mFilepathString(""),
					mSdlTexture(nullptr),
					mTextureWidth(1),
					mTextureHeight(1)
{
}

bool Texture::LoadTexture(IRenderer* pRenderer, const string& pFileName)
{
	mFilepathString = pFileName;

	SDL_Surface* surface = IMG_Load(mFilepathString.c_str());
	if (!surface)
	{
		Log::Error(LogType::Application, "Failed to load texture file :" + mFilepathString);
		return false;
	}
	mTextureWidth = surface->w;
	mTextureHeight = surface->h;


	switch (pRenderer->GetType())
	{
	case IRenderer::RendererType::SDL: //SDL
		return LoadSDL(dynamic_cast<RendererSDL*>(pRenderer), pFileName, surface);
		break;
	case IRenderer::RendererType::OPENGL: //OpenGl
		return LoadGL(dynamic_cast<RendererGl*>(pRenderer), pFileName, surface);
		break;
	default:
		return false;
		Log::Error(LogType::Render, "Renderer type is not set for load texture.");
		break;
	}
}

void Texture::UnloadTexture()
{
	if (mSdlTexture) 
	{
		SDL_DestroyTexture(mSdlTexture);
	}
	else 
	{
		glDeleteTextures(1, &mTextureId);
	}
}

void Texture::SetActive() const
{
	glBindTexture(GL_TEXTURE_2D, mTextureId);
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
