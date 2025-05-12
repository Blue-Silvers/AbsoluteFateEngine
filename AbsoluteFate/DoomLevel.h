#pragma once
#include "Actor.h"
#include "DoomFloor.h"
#include "DoomRoof.h"
#include "DoomWall.h"

class DoomLevel : public Actor
{
private:
	DoomFloor* mFloor;
	DoomRoof* mRoof;
	DoomWall* mWall001;
	DoomWall* mWall002;
	DoomWall* mWall003;
	DoomWall* mWall004;
	DoomWall* mWall005;
	DoomWall* mWall006;
	DoomWall* mWall007;
	DoomWall* mWall008;
	DoomWall* mWallDoor;

	vector<Actor*> mLevelElementList;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;

	inline vector<Actor*> GetLevelElements(){ return mLevelElementList; };
};

