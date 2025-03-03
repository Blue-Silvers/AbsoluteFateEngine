#include "Game.h"
#include "InputManager.h"
#include "RendererSDL.h"
#include "RendererGl.h"
#include <iostream>

//Initialize SDL at start of the game
Game::Game(std::string gameTitle, Scene* newScene, IRenderer::RendererType pRendererType): mTitle(gameTitle),
                                                                                            mIsRunning(true), 
                                                                                            mRendererType(pRendererType)
{
    switch (mRendererType)
    {
    case IRenderer::RendererType::SDL: //SDL

        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        {
            std::cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
        }
        else
        {
            std::cout << "SDL initialization succeeded!";
        }
        break;
    case IRenderer::RendererType::OPENGL: //OpenGl
        break;
    default:
        Log::Error(LogType::Render, "This render is not set.");
        break;
    }


    Init(newScene);
}

//Initialize game whith scenes
void Game::Init(Scene* newScene)
{
    mWindow = new Window{ 800,800 };
    //Choose good renderer
    switch (mRendererType)
    {
    case IRenderer::RendererType::SDL: //SDL
        mRenderer = new RendererSDL;
        break;
    case IRenderer::RendererType::OPENGL: //OpenGl
        mRenderer = new RendererGl;
        break;
    default:
        mRenderer = new RendererSDL;
        Log::Error(LogType::Render, "The render type is not set.");
        break;
    }
    mScene[0] = newScene;
    mScene[0]->SetRenderer(mRenderer);
    if (mWindow->Open(mTitle) && mRenderer->Initialize(*mWindow))
    {
        mScene[mLoadedScene]->Load();
        Loop();
    }
}

//Luck loop of the game
void Game::Loop()
{
    mScene[0]->Start();

    while (mIsRunning)
    {
        Time::ComputeDeltaTime();
        CheckInput();
        Update();
        Render();
        Time::DelayTime();
    }

    Close();
}

//Start and End drawing the game
void Game::Render()
{
    mRenderer->BeginDraw();

    ////Drawing Zone////
    mScene[mLoadedScene]->Render();//draw scene
    ///////////////////

    mRenderer->EndDraw();
}

//Update actual scene of the game
void Game::Update()
{
    mScene[0]->Update();
}

//Check if key is down when the game is open and possibilitie to close game
void Game::CheckInput()
{
    if (mIsRunning)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT: //close game
                mIsRunning = false;
                break;
            default:
                InputManager::Instance().HandleInputs(event);
                break;
            }
        }
    }

}

//Close game
void Game::Close()
{
    mWindow->Close();
}
