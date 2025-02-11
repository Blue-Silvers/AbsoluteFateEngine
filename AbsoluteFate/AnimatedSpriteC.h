#pragma once
#include "SpriteC.h"
#include <vector>
using namespace std;

class AnimatedSpriteC : public SpriteC
{
private:
	vector<Texture*> mAnimationTextures;
	float mCurrentFrame;
	float mAnimFps;

public:
	AnimatedSpriteC(Actor* pOwner, const vector<Texture*>& pTexture, int pDrawOrder = 100);
	virtual ~AnimatedSpriteC();
	AnimatedSpriteC() = delete;
	AnimatedSpriteC(const AnimatedSpriteC&) = delete;
	AnimatedSpriteC& operator=(const AnimatedSpriteC&) = delete;

	float GetAnimationFps() const { return mAnimFps; }
	void SetAnimationTextures(const vector<Texture*>& pTextures);
	void SetAnimationFps(float pFps);

	void Update() override;
};

