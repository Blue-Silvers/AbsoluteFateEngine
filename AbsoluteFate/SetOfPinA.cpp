#include "SetOfPinA.h"

void SetOfPinA::Start()
{
	mPinList.push_back(new PinA());
	mPinList.push_back(new PinA());
	mPinList.push_back(new PinA());
	mPinList.push_back(new PinA());
	mPinList.push_back(new PinA());
	mPinList.push_back(new PinA());

	mPinList[0]->AttachScene(GetScene());
	mPinList[0]->Start();
	//GetScene()->AddActor(mPinList[0]);
	mPinList[1]->AttachScene(GetScene());
	mPinList[1]->Start();
	//GetScene()->AddActor(mPinList[1]);
	mPinList[2]->AttachScene(GetScene());
	mPinList[2]->Start();
	//GetScene()->AddActor(mPinList[2]);
	mPinList[3]->AttachScene(GetScene());
	mPinList[3]->Start();
	//GetScene()->AddActor(mPinList[3]);
	mPinList[4]->AttachScene(GetScene());
	mPinList[4]->Start();
	//GetScene()->AddActor(mPinList[4]);
	mPinList[5]->AttachScene(GetScene());
	mPinList[5]->Start();
	//GetScene()->AddActor(mPinList[5]);

	mPinList[0]->SetPosition(Vector3(50, 0, 1));
	mPinList[1]->SetPosition(Vector3(55, -2, 1));
	mPinList[2]->SetPosition(Vector3(55, 2, 1));
	mPinList[3]->SetPosition(Vector3(60, -4, 1));
	mPinList[4]->SetPosition(Vector3(60, 0, 1));
	mPinList[5]->SetPosition(Vector3(60, 4, 1));
}

void SetOfPinA::Update()
{
}

void SetOfPinA::Destroy()
{
}
