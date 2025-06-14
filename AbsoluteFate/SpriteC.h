#pragma once
#include "Texture.h"
#include "Components.h"
#include "RendererSDL.h"
#include "Actor.h"
#include "Scene.h"
#include <vector>


class SpriteC : public Components
{
private:

protected:
	Texture mTexture;
	int mDrawOrder;
	int mTextureWidth;
	int mTextureHeight;

public:
	//Constructor
	SpriteC(Actor* pOwner, const Texture& pTexture, int pDrawOrder = 100);
	virtual ~SpriteC();
	SpriteC() = delete;
	SpriteC(const SpriteC&) = delete;
	SpriteC& operator= (const SpriteC&) = delete;

	//Define and draw texture
	virtual void SetTexture(const Texture& pTexture);
	virtual void Draw(IRenderer& pRenderer);

	//Getters
	int GetDrawOrder() const { return mDrawOrder; }
	int GetTexWidth() const { return mTextureWidth; }
	int GetTexHeight() const { return mTextureHeight; }


	virtual void OnStart() {};
	virtual void Update() {};
	virtual void OnEnd() {};
};