#include "Game.h"
#include <iostream>


//Initialize SDL at start of the game
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

//Initialize game whith scenes
void Game::Init(Scene* newScene)
{
    mWindow = new Window{ 800,800 };
    mRenderer = new Renderer;
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
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT: //close game
                mIsRunning = false;
                break;
            case SDL_KEYDOWN: //look if key is down
                mScene[0]->OnInput(event); //use input of the scene
                break;
            default:
                
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
