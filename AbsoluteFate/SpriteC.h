#pragma once
#include "Texture.h"
#include "Components.h"
#include "Renderer.h"
#include "Actor.h"
#include "Scene.h"
#include <vector>

//class Texture;

class SpriteC : public Components
{
private:

protected:
	Texture mTexture;
	int mDrawOrder;
	int mTextureWidth;
	int mTextureHeight;

public:
	SpriteC(Actor* pOwner, Texture& pTexture, int pDrawOrder = 100);
	virtual ~SpriteC();
	SpriteC() = delete;
	SpriteC(const SpriteC&) = delete;
	SpriteC& operator= (const SpriteC&) = delete;

	virtual void SetTexture(const Texture& pTexture);
	virtual void Draw(Renderer& pRenderer);

	//Getters
	int GetDrawOrder() const { return mDrawOrder; }
	int GetTexWidth() const { return mTextureWidth; }
	int GetTexHeight() const { return mTextureHeight; }


	virtual void OnStart() {};
	virtual void Update() {};
	virtual void OnEnd() {};
};

