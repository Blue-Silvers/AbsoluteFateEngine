#pragma once
#include "Actor.h"
#include "Rectangle.h"
#include "Window.h"
#include "MeshC.h"

#include <iostream>
#include <fstream>
#include <string>
#include <SDL.h>
#include <glew.h>
using namespace std;

class Texture;
class SpriteC;

class IRenderer
{
private:
    
protected:
    std::vector<SpriteC*> mSpritesList = { nullptr };
    std::vector<MeshC*> MeshComponentList = { nullptr };
    Matrix4Row mSpriteViewProj = Matrix4Row();

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
    //Base fonction
    virtual bool Initialize(Window& rWindow) = 0;
    virtual void AddMesh(MeshC*) = 0;
    virtual void RemoveMesh(MeshC*) = 0;
    virtual void BeginDraw() = 0;
    virtual void Draw() = 0;
    virtual void DrawMeshes() =0;
    virtual void DrawAllSprites() = 0;
    virtual void DrawSprite(Actor& pActor, const Texture& pTex, Rectangle pSourceRect, Vector2 pOrigin, Flip pFlip = Flip::None) const = 0;
    virtual void EndDraw() = 0;
    virtual void Close() = 0;
    virtual RendererType GetType() = 0;
};
