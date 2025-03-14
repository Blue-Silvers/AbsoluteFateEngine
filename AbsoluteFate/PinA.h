#pragma once
#include "Actor.h"
#include "MeshC.h"
#include "BoxCollider3DC.h"

class PinA : public Actor
{
private:
	MeshC* mMeshComponent;
	BoxCollider3DC* mBoxCollider;
	Vector3 mForce = Vector3( 0,0,0 );
public:
	void Start()override;
	void Update()override;
	void Destroy()override;
	BoxCollider3DC* GetBoxCollider() { return mBoxCollider; };
	void AddForce(Vector3 pForce);
};

