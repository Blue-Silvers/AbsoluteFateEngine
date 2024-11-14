#pragma once
class Components
{
	protected:
		bool mIsActive;
		//Actor& mOwner;
		int mUpdateOrder;

	public:
		Components(/*const Actor& pOwner,*/ int pUpdateOrder) 
		{
			//mOwner = pOwner;
			mUpdateOrder = pUpdateOrder;
		};
		Components(const Components&) = delete;
		virtual Components& operator= (const Components&) = delete;
		virtual void OnStart() = 0;
		virtual void Update() = 0;
		virtual void OnEnd() = 0;
};

