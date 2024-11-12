#pragma once
#include "Vector2D.h"
#include <SDL.h>
class Window
{
private:
	SDL_Window* mSdlWindow;
	Vector2D mDimensions;

public:
	Window(float width = 800, float pHeight = 800);
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	inline Vector2D GetDimensions() const 
	{
		return mDimensions;
	}
	inline SDL_Window* GetSdlWindow() const
	{
		return mSdlWindow;
	}

	bool Open(std::string gameTitle);
	void Close();
};

