#pragma once
#include "IInputListener.h"
#include <vector>

class InputEvent : public IInputListener
{
protected:
	std::vector<IInputListener*> mListeners {};

public:
	InputEvent();
	virtual void Subscribe(IInputListener* pListener);
	virtual void Unsubscribe(IInputListener* pListener);
	virtual void NotifyListeners(SDL_Event& pEvent) const;
	void OnNotify(SDL_Event& pEvent) {};
};

