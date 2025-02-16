#pragma once
#include "Rectangle.h"
#include "Color.h"
#include "Window.h"
#include "Actor.h"
#include "Texture.h"
#include "Log.h"
#include "Maths.h"
#include "SpriteC.h"
#include "SDL_image.h"
#include <vector>
class SpriteC;
class Texture;


class Renderer
{
private:
	SDL_Renderer* mSdlRenderer;
	std::vector<SpriteC*> mSpritesList;

public:
	Renderer();
	Renderer(const Renderer&) = delete;
	Renderer& operator= (const Renderer&) = delete;

	bool Initialize(Window& rWindow);
	void BeginDraw();
	void EndDraw();
	void Close();

	void DrawRect(Rectangle& rRect);
	void DrawRectColor(Rectangle& rRect, Color& rColor);

	//Texture
	SDL_Renderer* GetSdlRenderer() { return mSdlRenderer; };

	enum class Flip
	{
		None = SDL_FLIP_NONE,
		Horizontal = SDL_FLIP_HORIZONTAL,
		Vertical = SDL_FLIP_VERTICAL
	};

	//SpriteComponent
	void Draw();
	void DrawAllSprites();
	void DrawSprite(Actor& pActor, Texture& pTexture, Rectangle pSourceRect, Vector2D pOrigin, Flip pFlip) const;
	void AddSprite(SpriteC* pSprite);
	void RemoveSprite(SpriteC* pSprite);
};


