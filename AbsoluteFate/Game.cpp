#include "Game.h"
#include <iostream>

Game::Game(std::string gameTitle): mTitle(gameTitle),mIsRunning(true)
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

    Init();
}

void Game::Init()
{
    mWindow = new Window{ 800,800 };
    mRenderer = new Renderer;
    mScene = new Scene{"Test"};
    mScene->SetRenderer(mRenderer);
    if (mWindow->Open(mTitle) && mRenderer->Initialize(*mWindow))
    {
        Loop();
    }
}

void Game::Loop()
{
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
    mScene->Render();
    /*mRenderer->BeginDraw();
    
    Rectangle rRect = { {300,300},{200,300} };
    mRenderer->DrawRect(rRect);
    mRenderer->EndDraw();*/
}

void Game::Update()
{
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
            default:
                //Send input to scene
                break;
            }
        }
    }

}

void Game::Close()
{
    mWindow->Close();
}
