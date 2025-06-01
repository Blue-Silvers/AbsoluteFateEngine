#include "DoomLevel.h"

void DoomLevel::Start()
{
	mFloor = new DoomFloor();
	mFloor->AttachScene(GetScene());
	mLevelElementList.push_back(mFloor);

	mRoof = new DoomRoof();
	mRoof->AttachScene(GetScene());
	mLevelElementList.push_back(mRoof);

	mWall001 = new DoomWall();
	mWall001->AttachScene(GetScene());
	mLevelElementList.push_back(mWall001);
	
	mWall002 = new DoomWall();
	mWall002->AttachScene(GetScene());
	mLevelElementList.push_back(mWall002);

	mWall003 = new DoomWall();
	mWall003->AttachScene(GetScene());
	mLevelElementList.push_back(mWall003);

	mWall004 = new DoomWall();
	mWall004->AttachScene(GetScene());
	mLevelElementList.push_back(mWall004);

	mWall005 = new DoomWall();
	mWall005->AttachScene(GetScene());
	mLevelElementList.push_back(mWall005);

	mWall006 = new DoomWall();
	mWall006->AttachScene(GetScene());
	mLevelElementList.push_back(mWall006);

	mWall007 = new DoomWall();
	mWall007->AttachScene(GetScene());
	mLevelElementList.push_back(mWall007);

	mWall008 = new DoomWall();
	mWall008->AttachScene(GetScene());
	mLevelElementList.push_back(mWall008);

	mWallDoor = new DoomWall();
	mWallDoor->AttachScene(GetScene());
	mLevelElementList.push_back(mWallDoor);


	for (Actor* actor : mLevelElementList)
	{
		actor->Start();
	}

	mWall001->SetScale(Vector3{ 35, 1, 5 });		//scale		001
	mWall001->SetPosition(Vector3{ 25, 50, 2 });	//location	001
	mWall002->SetScale(Vector3{ 35, 1, 5 });		//scale		002
	mWall002->SetPosition(Vector3{ 25, -50, 2 });	//location	002
	mWall003->SetScale(Vector3{ 1, 50, 5 });		//scale		003
	mWall003->SetPosition(Vector3{ 60, 0, 2 });		//location	003
	mWall004->SetScale(Vector3{ 1, 23, 5 });		//scale		004
	mWall004->SetPosition(Vector3{ -10, 27, 2 });	//location	004
	mWall004->GetMeshComponent()->SetTiling({23,5});
	mWall005->SetScale(Vector3{ 1, 23, 5 });		//scale		005
	mWall005->SetPosition(Vector3{ -10, -27, 2 });	//location	005
	mWall005->GetMeshComponent()->SetTiling({ 23,5 });
	mWall006->SetScale(Vector3{ 15, 1, 5 });		//scale		006
	mWall006->SetPosition(Vector3{ -25, 20, 2 });	//location	006
	mWall006->GetMeshComponent()->SetTiling({ 15,5 });
	mWall007->SetScale(Vector3{ 15, 1, 5 });		//scale		007
	mWall007->SetPosition(Vector3{ -25, -20, 2 });	//location	007
	mWall007->GetMeshComponent()->SetTiling({ 15,5 });
	mWall008->SetScale(Vector3{ 1, 20, 5 });		//scale		008
	mWall008->SetPosition(Vector3{ -40, 0, 2 });	//location	008
	mWall008->GetMeshComponent()->SetTiling({ 20,5 });

	mWallDoor->SetScale(Vector3{ 1, 4, 2 });		//scale		Door
	mWallDoor->SetPosition(Vector3{ -10, 0, 6 });	//location	Door
	mWallDoor->GetMeshComponent()->SetTiling({ 4,2 });
}

void DoomLevel::Update()
{
}

void DoomLevel::Destroy()
{
}