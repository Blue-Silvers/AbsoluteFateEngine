#pragma once
#include "Vector2.h"

#include <SDL.h>

class Window
{
private:
	SDL_Window* mSdlWindow;
	Vector2 mDimensions;

public:
	//Construcor
	Window(float width = 800, float pHeight = 800);
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	//Getters
	inline Vector2 GetDimensions() const 
	{
		return mDimensions;
	}
	inline SDL_Window* GetSdlWindow() const
	{
		return mSdlWindow;
	}

	//State
	bool Open(std::string gameTitle);
	void Close();
};