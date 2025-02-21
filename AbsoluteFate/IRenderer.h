#pragma once
#include "Actor.h"
#include "Rectangle.h"
#include "Window.h"

class Texture;

class IRenderer
{
private:

public:
    enum class Flip //flip renderer
    {
        None = SDL_FLIP_NONE,
        Horizontal = SDL_FLIP_HORIZONTAL,
        Vertical = SDL_FLIP_VERTICAL
    };

    enum class RendererType //use SDL or OpenGL
    {
        SDL,
        OPENGL
    };
    virtual ~IRenderer() = default;
    //Bas fonction
    virtual bool Initialize(Window& rWindow) = 0;
    virtual void BeginDraw() = 0;
    virtual void Draw() = 0;
    virtual void DrawAllSprites() = 0;
    virtual void DrawSprite(Actor& pActor, const Texture& pTex, Rectangle pSourceRect, Vector2D pOrigin, Flip pFlip = Flip::None) const = 0;
    virtual void EndDraw() = 0;
    virtual void Close() = 0;
    virtual RendererType GetType() = 0;
};
