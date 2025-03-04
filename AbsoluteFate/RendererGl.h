#pragma once
#include "IRenderer.h"
#include "VertexArray.h"
#include "ShaderProgram.h"

class SpriteC;

class RendererGl : public IRenderer
{
private:
	Window* mWindow;
	VertexArray* mSpriteVao;
	SDL_GLContext mContext;
	ShaderProgram* mSpriteShaderProgram;
	Matrix4Row mSpriteViewProj;
	Matrix4Row mView;
	Matrix4Row mProj;

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

	void DrawMeshes() override;
	void AddMesh(MeshC* pMesh) override;
	void RemoveMesh(MeshC* pMesh) override;

	void Close() override;
	RendererType GetType() override;
};

