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

public:
	RendererSDL();

	RendererSDL(const RendererSDL&) = delete;
	RendererSDL& operator= (const RendererSDL&) = delete;

	//Draw rectancle
	void DrawRect(Rectangle& rRect);
	void DrawRectColor(Rectangle& rRect, Color& rColor);

	//Texture
	SDL_Renderer* GetSdlRenderer() { return mSdlRenderer; };

				//Base fonction//
	bool Initialize(Window& rWindow) override;
	//Draw fonction
	void BeginDraw() override;
	void Draw() override;
	void EndDraw() override;
	//Draw Sprites
	void DrawAllSprites() override;
	void DrawSprite(Actor& pActor, const Texture& pTexture, Rectangle pSourceRect, Vector2 pOrigin, IRenderer::Flip pFlip = IRenderer::Flip::None) const override;
	void AddSprite(SpriteC* pSprite) override;
	void RemoveSprite(SpriteC* pSprite) override;
	//Close
	void Close() override;
	//Getter
	IRenderer::RendererType GetType() override;
};


