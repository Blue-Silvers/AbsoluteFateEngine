#pragma once

class Actor;
class Renderer;

class Components
{
	protected:
		bool mIsActive;
		Actor* mOwner;
		int mUpdateOrder;

	public:
		Components(Actor* pOwner, int pUpdateOrder); //Component constructor with owner and default update order
		Components() = delete; //Delete default constructor
		virtual void OnStart() = 0;
		virtual void Update() = 0;
		virtual void OnEnd() = 0;
};

