#include "SetOfPinA.h"

#include "Log.h"

void SetOfPinA::Start()
{
	mPinList.push_back(new PinA());
	mPinList.push_back(new PinA());
	mPinList.push_back(new PinA());
	mPinList.push_back(new PinA());
	mPinList.push_back(new PinA());
	mPinList.push_back(new PinA());

	for (Actor* actor : mPinList)
	{
		actor->AttachScene(GetScene());
		actor->Start();
	}

	mPinList[0]->SetPosition(Vector3(50, 0, -1));
	mPinList[1]->SetPosition(Vector3(55, -2, -1));
	mPinList[2]->SetPosition(Vector3(55, 2, -1));
	mPinList[3]->SetPosition(Vector3(60, -4, -1));
	mPinList[4]->SetPosition(Vector3(60, 0, -1));
	mPinList[5]->SetPosition(Vector3(60, 4, -1));
}

void SetOfPinA::Update()
{
	restart = true;
	for (Actor* actor : mPinList)
	{
		actor->Update();
		
		if (PinA* pin = dynamic_cast<PinA*>(actor)) 
		{
			if (pin->IsHit() == false)
			{
				restart = false;
			}
		}
	}
	if (restart == true) 
	{
		timeBeforeRestart -= 0.1F;
		if (timeBeforeRestart <= 0)
		{
			timeBeforeRestart = 20;
			Destroy();
			Start();
		}
	}
}

void SetOfPinA::Destroy()
{
	mPinList.clear();
}
