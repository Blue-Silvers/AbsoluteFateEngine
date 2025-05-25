#include "PinA.h"

#include "Time.h"
#include "Asset.h"
#include <iostream>

#include "Log.h"

void PinA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/pin2.png", "Pin_TEX");
	Asset::LoadMesh("Resources/3D_Models/pin.obj", "pin");
	//Actor
	SetScale(Vector3{ 0.5, 0.5, 0.5 }); //scale
	SetPosition(Vector3{ 0, 0, 0 }); //location
	mTransform.RotateXInDegrees(90);
	mMeshComponent = new MeshC(this, &Asset::GetMesh("pin"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("Pin_TEX")});

	AddComponent(mMeshComponent);

	mBoxCollider = new BoxCollider3DBowlingC(this);
	mBoxCollider->SetCustomSize(Vector3(2, 3, 3));
	AddComponent(mBoxCollider);

	AddTag("bowlingPin");
}

void PinA::Update()
{

	if (mForce.x != 0 && mForce.y != 0) 
	{
		SetPosition(mTransform.GetPosition() + mForce*0.1F);
		mTransform.RotateXInDegrees(mForce.y );
		mTransform.RotateYInDegrees(mForce.x );
	}

	if (GetBoxCollider()->OnCollide() == true)
	{
		bool hitPin = false;
		for (string tag : GetBoxCollider()->GetCollideActor()->GetTags())
		{
			if (tag == "bowlingPin")
			{
				hitPin = true;

			}
		}
		if (hitPin == true)
		{
			if (PinA* pinA = dynamic_cast<PinA*>(GetBoxCollider()->GetCollideActor()))
			{
				pinA->AddForce(GetBoxCollider()->GetDistance());
			}
		}
	}
}

void PinA::Destroy()
{
	delete mBoxCollider;
	delete mMeshComponent;
}

BoxCollider3DBowlingC* PinA::GetBoxCollider()
{
	for (Components* component : GetAllComponent())
	{
		if (BoxCollider3DBowlingC* boxCollider3DC = dynamic_cast<BoxCollider3DBowlingC*>(component))
		{
			return boxCollider3DC;
		}
	}
}

void PinA::AddForce(Vector3 pForce)
{
	mForce = pForce * -2;
	mForce.z *= -1;
	Vector3 newPos = mTransform.GetPosition() + (pForce * -1);
	newPos.z = -1;
	for (int x = 0; x <= 1000; x++)
	{
		SetPosition(Vector3::Lerp(mTransform.GetPosition(), newPos, 0.0002F));
		mTransform.RotateXInDegrees(pForce.y / 1000);
		mTransform.RotateYInDegrees(pForce.x / 1000);
	}
	hit = true;
}
