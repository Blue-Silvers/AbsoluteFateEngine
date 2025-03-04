#include "RendererSDL.h"
#include "SpriteC.h"

RendererSDL::RendererSDL() : mSdlRenderer(nullptr)
{
}

//Initialize render variable
bool RendererSDL::Initialize(Window& rWindow)
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
void RendererSDL::BeginDraw()
{
    SDL_SetRenderDrawColor(mSdlRenderer, 120, 120, 255, 255);
    SDL_RenderClear(mSdlRenderer);
}

//Stop drawing whith render variable
void RendererSDL::EndDraw()
{
    SDL_RenderPresent(mSdlRenderer);
}


//Destroy renderer contain render variable
void RendererSDL::Close()
{
    SDL_DestroyRenderer(mSdlRenderer);
}

//Draw white rectangle (no color) whith rectangle class
void RendererSDL::DrawRect(Rectangle& rRect)
{
    SDL_SetRenderDrawColor(mSdlRenderer, 255, 255, 255, 255);
    SDL_Rect sdlRect = rRect.ToSdlRect();
    SDL_RenderFillRect(mSdlRenderer, &sdlRect);
}

//Draw rectangle whith rectangle class and set color whith color class
void RendererSDL::DrawRectColor(Rectangle& rRect, Color& rColor)
{
    SDL_SetRenderDrawColor(mSdlRenderer, (Uint8)rColor.r, (Uint8)rColor.g, (Uint8)rColor.b, (Uint8)rColor.a);
    SDL_Rect sdlRect = rRect.ToSdlRect();
    SDL_RenderFillRect(mSdlRenderer, &sdlRect);
}

void RendererSDL::Draw()
{
    DrawAllSprites();
}

void RendererSDL::DrawAllSprites()
{
    for (SpriteC* sprite : mSpritesList)
    {
        sprite->Draw(*this);
    }
}

void RendererSDL::DrawSprite(Actor& pActor, const Texture& pTexture, Rectangle pSourceRect, Vector2 pOrigin, Flip pFlip) const
{

    SDL_Rect destinationRect;
    Transform transform = pActor.GetTransform();
    destinationRect.w = static_cast<int>(pTexture.GetWidth() * transform.GetScale().x);
    destinationRect.h = static_cast<int>(pTexture.GetHeight() * transform.GetScale().y);
    destinationRect.x = static_cast<int>(transform.GetPosition().x - pOrigin.x);
    destinationRect.y = static_cast<int>(transform.GetPosition().y - pOrigin.y);

    SDL_Rect* sourceSDL = nullptr;
    if (pSourceRect != Rectangle::NullRect)
    {
        sourceSDL = new SDL_Rect
        {
                Maths::Round(pSourceRect.position.x),
                Maths::Round(pSourceRect.position.y),
                Maths::Round(pSourceRect.dimensions.x),
                Maths::Round(pSourceRect.dimensions.y)
        };
    }

                                                //Debug draw sqr//
    //Rectangle rBox = {{(float)destinationRect.x,(float)destinationRect.y},{(float)destinationRect.w,(float)destinationRect.h}};
    //SDL_SetRenderDrawColor(mSdlRenderer, 255, 255, 255, 255);
    //SDL_Rect sdlRect = rBox.ToSdlRect();
    //SDL_RenderFillRect(mSdlRenderer, &sdlRect);


    SDL_RenderCopyEx(mSdlRenderer, pTexture.GetSdlTexture(), sourceSDL,  &destinationRect, -Maths::ToDeg(transform.GetRotation2D()), nullptr, SDL_FLIP_NONE);
    delete sourceSDL;
}


void RendererSDL::AddSprite(SpriteC* pSprite)
{
    int spriteDrawOrder = pSprite->GetDrawOrder();
    vector<SpriteC*>::iterator spriteComponent;
    for (spriteComponent = mSpritesList.begin(); spriteComponent != mSpritesList.end(); ++spriteComponent) 
    {
        if (spriteDrawOrder < (*spriteComponent)->GetDrawOrder()) 
        {
            break;
        }
    }
    mSpritesList.insert (spriteComponent, pSprite);
}

void RendererSDL::RemoveSprite(SpriteC* pSprite)
{
    vector<SpriteC*>::iterator spriteComponent;
    spriteComponent = find(mSpritesList.begin(), mSpritesList.end(), pSprite);
    mSpritesList.erase(spriteComponent);
}

IRenderer::RendererType RendererSDL::GetType()
{
    return IRenderer::RendererType::SDL;
}
