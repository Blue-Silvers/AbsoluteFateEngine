#pragma once
#include "Actor.h"
#include "MeshC.h" 
#include "DoomBoxCollider3DC.h"

class DoomDoor : public Actor
{
private:
	MeshC* mMeshComponent;
	Shader mTessVertexShader, mTessFragShader, mTessControlShader, mTessEvalShader;
	ShaderProgram mTessProgram;
	bool mDoorOpen = false;
	float mDoorSpeed = 0.05F;

	DoomBoxCollider3DC* mBoxCollider;

public:
	void Start()override;
	void Restart();
	void Update()override;
	void Destroy()override;
	void OpenDoor();
	void CloseDoor();

			/*	Getter \ Setter	*/
	inline bool GetDoorOpen() { return mDoorOpen; };
	inline void SetDoorOpen(bool isOpen) { mDoorOpen = isOpen; };
};

