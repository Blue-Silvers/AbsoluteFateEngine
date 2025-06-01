#include "AnimatedSpriteC.h"
#include "Time.h"

AnimatedSpriteC::AnimatedSpriteC(Actor* pOwner, const vector<Texture>& pTexture, int pDrawOrder) : SpriteC(pOwner, pTexture[0], pDrawOrder), mCurrentFrame(0.0f), mAnimFps(24.0f)
{
	SetAnimationTextures(pTexture);
}

AnimatedSpriteC::~AnimatedSpriteC()
{
}

void AnimatedSpriteC::SetAnimationTextures(const vector<Texture>& pTextures)
{
	mAnimationTextures = pTextures;
	if (mAnimationTextures.size() > 0) 
	{
		SetTexture(mAnimationTextures[0]);
	}

}

void AnimatedSpriteC::SetAnimationFps(float pFps)
{
	mAnimFps = pFps;
}

void AnimatedSpriteC::Update()
{
	SpriteC::Update();

	if (mAnimationTextures.size() == 0)
	{
		return;
	}

	mCurrentFrame += mAnimFps * Time::deltaTime;
	while (mCurrentFrame >= mAnimationTextures.size())
	{
		mCurrentFrame -= mAnimationTextures.size();
	}

	SetTexture(mAnimationTextures[static_cast<int>(mCurrentFrame)]);
}