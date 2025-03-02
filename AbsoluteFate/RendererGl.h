#pragma once
#include "IRenderer.h"
#include "VertexArray.h"
#include "ShaderProgram.h"

class SpriteC;

class RendererGl : public IRenderer
{
private:
	Window* mWindow;
	VertexArray* mVao;
	SDL_GLContext mContext;
	std::vector<SpriteC*> mSprites;
	ShaderProgram* mShaderProgram;

public:
	RendererGl();
	virtual ~RendererGl();
	RendererGl(const RendererGl&) = delete;
	RendererGl& operator=(const RendererGl&) = delete;

	bool Initialize(Window& rWindow) override;
	void SetShaderProgram(ShaderProgram* pShaderProgram);
	void BeginDraw() override;
	void Draw() override;
	void DrawAllSprites() override;
	void EndDraw() override;

	void DrawSprite(Actor& pActor, const Texture& pTex, Rectangle pSourceRect, Vector2 pOrigin, Flip pFlip = Flip::None) const;
	void AddSprite(SpriteC* pSprite);
	void RemoveSprite(SpriteC* pSprite);
	void Close() override;
	RendererType GetType() override;
};

