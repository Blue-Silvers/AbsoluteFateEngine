#pragma once
#include "Actor.h"
#include "MeshC.h"
#include "BoxCollider3DC.h"
#include "BoxCollider3DBowlingC.h"

class PinA : public Actor
{
private:
	MeshC* mMeshComponent;
	BoxCollider3DBowlingC* mBoxCollider;
	Vector3 mForce = Vector3( 0,0,0 );
	bool hit = false;

public:
	void Start()override;
	void Update()override;
	void Destroy()override;
	BoxCollider3DBowlingC* GetBoxCollider();
	void AddForce(Vector3 pForce);
	bool IsHit() { return hit; };
};

