#pragma once
#include "Color.h"
#include "Texture.h"
#include "Log.h"
#include "Maths.h"

#include "SDL_image.h"
#include "IRenderer.h"
#include <vector>

class SpriteC;

class RendererSDL : public IRenderer
{
private:
	SDL_Renderer* mSdlRenderer;
	std::vector<SpriteC*> mSpritesList;

public:
	RendererSDL();

	RendererSDL(const RendererSDL&) = delete;
	RendererSDL& operator= (const RendererSDL&) = delete;

	bool Initialize(Window& rWindow) override;
	void BeginDraw() override;
	void EndDraw() override;
	void Close() override;

	void DrawRect(Rectangle& rRect);
	void DrawRectColor(Rectangle& rRect, Color& rColor);

	//Texture
	SDL_Renderer* GetSdlRenderer() { return mSdlRenderer; };

	//SpriteComponent
	void Draw() override;
	void DrawAllSprites() override;
	void DrawMeshes() override {};
	void DrawSprite(Actor& pActor, const Texture& pTexture, Rectangle pSourceRect, Vector2 pOrigin, IRenderer::Flip pFlip = IRenderer::Flip::None) const;
	void AddSprite(SpriteC* pSprite);
	void RemoveSprite(SpriteC* pSprite);


	IRenderer::RendererType GetType() override;
};


