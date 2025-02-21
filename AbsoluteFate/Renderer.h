#pragma once
#include "Color.h"
#include "Texture.h"
#include "Log.h"
#include "Maths.h"
#include "SpriteC.h"
#include "SDL_image.h"
#include "IRenderer.h"
#include <vector>
//in IRenderer
#include "Actor.h"
#include "Rectangle.h"
#include "Window.h"
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

	virtual bool Initialize(Window& rWindow);
	virtual void BeginDraw();
	virtual void EndDraw();
	virtual void Close();

	void DrawRect(Rectangle& rRect);
	void DrawRectColor(Rectangle& rRect, Color& rColor);

	//Texture
	SDL_Renderer* GetSdlRenderer() { return mSdlRenderer; };

	//SpriteComponent
	virtual void Draw();
	virtual void DrawAllSprites();
	virtual void DrawSprite(Actor& pActor, const Texture& pTexture, Rectangle pSourceRect, Vector2D pOrigin, Flip pFlip = Flip::None) const;
	void AddSprite(SpriteC* pSprite);
	void RemoveSprite(SpriteC* pSprite);

	virtual RendererType GetType();
};


