#include "Game.h"
#include <iostream>

Game::Game(std::string gameTitle, Scene* newScene): mTitle(gameTitle),mIsRunning(true)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
    }
    else
    {
        std::cout << "SDL initialization succeeded!";
    }
    mTitle = gameTitle;

    Init(newScene);
}

void Game::Init(Scene* newScene)
{
    mWindow = new Window{ 800,800 };
    mRenderer = new Renderer;
    mScene[0] = newScene;
    mScene[0]->SetRenderer(mRenderer);
    if (mWindow->Open(mTitle) && mRenderer->Initialize(*mWindow))
    {
        Loop();
    }
}

void Game::Loop()
{
    mScene[0]->Start();

    while (mIsRunning)
    {
        CheckInput();
        Update();
        Render();
    }

    Close();
}

void Game::Render()
{
    
    mRenderer->BeginDraw();
    mScene[0]->Render();
    /*Rectangle rRect = { {300,300},{200,300} };
    mRenderer->DrawRect(rRect);*/
    mRenderer->EndDraw();
}

void Game::Update()
{
    mScene[0]->Update();
}

void Game::CheckInput()
{
    if (mIsRunning)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                mIsRunning = false;
                break;
            case SDL_KEYDOWN:
                mScene[0]->OnInput(event);
                break;
            default:
                
                break;
            }
        }
    }

}

void Game::Close()
{
    mWindow->Close();
}
