#pragma once
#include "Texture.h"
#include "Components.h"

class SpriteC : public Components
{
private:

protected:
	Texture* mTexture;
	int mDrawOrder;
	int mTextureWidth;
	int mTextureHeight;
public:
	SpriteC(Actor* pOwner, Texture* pTexture, int pDrawOrder = 100);
	virtual ~SpriteC();
	SpriteC() = delete;
	SpriteC(const SpriteC&) = delete;
	SpriteC& operator= (const SpriteC&) = delete;

	virtual void SetTexture(Texture* pTexture);
	virtual void Draw(Renderer& pRenderer);

	//Getters
	int GetDrawOrder() const { return mDrawOrder; }
	int GetTextureWidth() const { return mTextureWidth; }
	int GetTextureHeight() const { return mTextureHeight; }
};

