#pragma once
#include "Actor.h"
#include "MeshC.h" 
#include "BoxCollider3DC.h"

class DoomDoor : public Actor
{
private:
	MeshC* mMeshComponent;
	Shader mTessVertexShader, mTessFragShader, mTessControlShader, mTessEvalShader;
	ShaderProgram mTessProgram;
	bool mDoorOpen = false;
	float mDoorSpeed = 0.05;

	BoxCollider3DC* mBoxCollider;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
	void OpenDoor();
	void CloseDoor();

			/*	Getter \ Setter	*/
	inline bool GetDoorOpen() { return mDoorOpen; };
	inline void SetDoorOpen(bool isOpen) { mDoorOpen = isOpen; };
};

