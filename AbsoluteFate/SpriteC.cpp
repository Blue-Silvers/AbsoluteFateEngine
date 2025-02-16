#include "SpriteC.h"
#include "Actor.h"
#include "Scene.h"
#include <vector>

SpriteC::SpriteC(Actor* pOwner, Texture* pTexture, int pDrawOrder) : Components(pOwner, pDrawOrder), mTexture(pTexture), mDrawOrder(pDrawOrder), mTextureWidth(pTexture->GetWidth()), mTextureHeight(pTexture->GetHeight())
{
	mOwner->GetScene()->GetRenderer()->AddSprite(this);
}


SpriteC::~SpriteC()
{
	mOwner->GetScene()->GetRenderer()->RemoveSprite(this);
}

void SpriteC::SetTexture(Texture* pTexture)
{
	mTexture = pTexture;
	mTexture->UpdateInfo(mTextureWidth, mTextureHeight);
}

void SpriteC::Draw(Renderer& pRenderer)
{
	Vector2D origin{ mTextureWidth / 2.0f, mTextureHeight / 2.0f };
	pRenderer.DrawSprite(*mOwner, *mTexture, Rectangle(), origin, Flip::None);
}
