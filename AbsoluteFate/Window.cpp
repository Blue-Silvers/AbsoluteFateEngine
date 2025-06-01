#include "Window.h"
#include "Log.h"

Window::Window(float pWidth, float pHeight)  : mSdlWindow(nullptr), mDimensions ({pWidth, pHeight})
{
}

//Open window
bool Window::Open(std::string gameTitle)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        Log::Error(LogType::Video, "Unable to initialize video");
        return false;
    }
    mSdlWindow = SDL_CreateWindow(gameTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, static_cast<int>(mDimensions.x), static_cast<int>(mDimensions.y), SDL_WINDOW_OPENGL); //set game window name and use SDL
    if (!mSdlWindow)
    {
        Log::Error(LogType::System, "Failed to create window"); // window can't open
        return false;
    }
    return true;

}

//Kill window
void Window::Close()
{
    SDL_DestroyWindow(mSdlWindow);
}