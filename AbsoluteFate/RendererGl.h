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
	Matrix4Row mView;
	Matrix4Row mProj;

public:
	RendererGl();
	virtual ~RendererGl();
	RendererGl(const RendererGl&) = delete;
	RendererGl& operator=(const RendererGl&) = delete;

	void SetShaderProgram(ShaderProgram* pShaderProgram);

					//Base fonction//
	bool Initialize(Window& rWindow) override;
	void SetViewMatrix(Matrix4Row pView) override;
	//Draw fonction
	void BeginDraw() override;
	void Draw() override;
	void DrawAllSprites() override;
	void EndDraw() override;
	//Draw Sprites
	void DrawSprite(Actor& pActor, const Texture& pTex, Rectangle pSourceRect, Vector2 pOrigin, Flip pFlip = Flip::None) const override;
	void AddSprite(SpriteC* pSprite) override;
	void RemoveSprite(SpriteC* pSprite) override;
	//Draw Meshs
	void DrawAllMeshes() override;
	void AddMesh(MeshC* pMesh) override;
	void RemoveMesh(MeshC* pMesh) override;
	//Close
	void Close() override;
	//Getter
	RendererType GetType() override;
	Matrix4Row GetProj() override { return mProj; }
};

