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
	for (Actor* actor : mPinList)
	{
		actor->Update();
	}

	for (Actor* actor : mPinList)
	{
		if (PinA* pinA = dynamic_cast<PinA*>(actor))
		{
			if (pinA->GetBoxCollider()->OnCollide() == true)
			{				Log::Info("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

				//Log::Info("" + std::to_string(GetBoxCollider()->GetDistance().x) + ", " + std::to_string(GetBoxCollider()->GetDistance().y) + ", " + std::to_string(GetBoxCollider()->GetDistance().z));

				bool hitPin = false;
				for (string tag : pinA->GetBoxCollider()->GetCollideActor()->GetTags())
				{
					if (tag == "bowlingPin")
					{
						hitPin = true;

					}
				}
				if (hitPin == true)
				{
					if (PinA* colidePinA = dynamic_cast<PinA*>(pinA->GetBoxCollider()->GetCollideActor()))
					{
						colidePinA->AddForce(colidePinA->GetBoxCollider()->GetDistance());
					}
				}
			}
		}
	}

}

void SetOfPinA::Destroy()
{
	mPinList.clear();
}
