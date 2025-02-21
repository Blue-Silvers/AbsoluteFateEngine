#include "SpriteC.h"

SpriteC::SpriteC(Actor* pOwner, const Texture& pTexture, int pDrawOrder) :Components(pOwner),
																	mTexture(pTexture),
																	mDrawOrder(pDrawOrder),
																	mTextureWidth(pTexture.GetWidth()),
																	mTextureHeight(pTexture.GetHeight())
{
	mOwner->GetScene()->GetRenderer()->AddSprite(this);
}

SpriteC::~SpriteC()
{
	mOwner->GetScene()->GetRenderer()->RemoveSprite(this);
}

void SpriteC::SetTexture(const Texture& pTexture)
{
	mTexture = pTexture;
	mTexture.UpdateInfo(mTextureWidth, mTextureHeight);
}

void SpriteC::Draw(RendererSDL& pRenderer)
{
	Vector2 origin{ mTextureWidth / 2.0f, mTextureHeight / 2.0f };
	pRenderer.DrawSprite(*mOwner, mTexture, Rectangle((0,0), ((float)mTextureWidth, (float)mTextureHeight)), origin, RendererSDL::Flip::None);
}

