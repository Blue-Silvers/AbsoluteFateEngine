#pragma once
#include "IInputListener.h"
#include <vector>

class InputEvent
{
protected:
	std::vector<IInputListener*> mListeners {};

public:
	InputEvent();
	~InputEvent();
	virtual void Subscribe(IInputListener* pListener); //listen new input
	virtual void Unsubscribe(IInputListener* pListener); //Stop listening specific input
	virtual void NotifyListeners(SDL_Event& pEvent) const; 
};