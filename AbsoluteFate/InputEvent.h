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
	virtual void Subscribe(IInputListener* pListener);
	virtual void Unsubscribe(IInputListener* pListener);
	virtual void NotifyListeners(SDL_Event& pEvent) const;
};

