#include "Renderer.h"
#include "SDL_image.h"
Renderer::Renderer() :mSdlRenderer(nullptr)
{
}

//Initialize render variable
bool Renderer::Initialize(Window& rWindow)
{
    mSdlRenderer = SDL_CreateRenderer(rWindow.GetSdlWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!mSdlRenderer)
    {
        Log::Error(LogType::Video, "Failed to create Renderer");
        return false;
    }
    if (IMG_Init(IMG_INIT_PNG) == 0) // SDL Image
    {
        Log::Error(LogType::Video, "Unable to initialize SDL_Image");
        return false;
    }

    return true;
}

//Start drawing whith render variable
void Renderer::BeginDraw()
{
    SDL_SetRenderDrawColor(mSdlRenderer, 120, 120, 255, 255);
    SDL_RenderClear(mSdlRenderer);
}

//Stop drawing whith render variable
void Renderer::EndDraw()
{
    SDL_RenderPresent(mSdlRenderer);
}


//Destroy renderer contain render variable
void Renderer::Close()
{
    SDL_DestroyRenderer(mSdlRenderer);
}

//Draw white rectangle (no color) whith rectangle class
void Renderer::DrawRect(Rectangle& rRect)
{
    SDL_SetRenderDrawColor(mSdlRenderer, 255, 255, 255, 255);
    SDL_Rect sdlRect = rRect.ToSdlRect();
    SDL_RenderFillRect(mSdlRenderer, &sdlRect);
}

//Draw rectangle whith rectangle class and set color whith color class
void Renderer::DrawRectColor(Rectangle& rRect, Color& rColor)
{
    SDL_SetRenderDrawColor(mSdlRenderer, rColor.r, rColor.g, rColor.b, rColor.a);
    SDL_Rect sdlRect = rRect.ToSdlRect();
    SDL_RenderFillRect(mSdlRenderer, &sdlRect);
}
