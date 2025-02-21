#include "SpriteC.h"

SpriteC::SpriteC(Actor* pOwner, const Texture& pTexture, int pDrawOrder) :Components(pOwner),
																	mTexture(pTexture),
																	mDrawOrder(pDrawOrder),
																	mTextureWidth(pTexture.GetWidth()),
																	mTextureHeight(pTexture.GetHeight())
{
	if (RendererSDL* pRendererSDL = dynamic_cast<RendererSDL*>(mOwner->GetScene()->GetRenderer()))
	{
		pRendererSDL->AddSprite(this);
	}
}

SpriteC::~SpriteC()
{
	if (RendererSDL* pRendererSDL = dynamic_cast<RendererSDL*>(mOwner->GetScene()->GetRenderer()))
	{
		pRendererSDL->RemoveSprite(this);
	}
}

void SpriteC::SetTexture(const Texture& pTexture)
{
	mTexture = pTexture;
	mTexture.UpdateInfo(mTextureWidth, mTextureHeight);
}

void SpriteC::Draw(IRenderer& pRenderer)
{
	Vector2 origin{ mTextureWidth / 2.0f, mTextureHeight / 2.0f };
	pRenderer.DrawSprite(*mOwner, mTexture, Rectangle((0,0), ((float)mTextureWidth, (float)mTextureHeight)), origin, RendererSDL::Flip::None);
}

