#include "PinA.h"

#include "Time.h"
#include "Asset.h"
#include <iostream>

#include "Log.h"

void PinA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/White.png", "Pin_TEX");
	Asset::LoadMesh("Resources/3D_Models/BowlingPin.obj", "pin");
	//Actor
	SetScale(Vector3{ 0.75, 0.75, 0.75 }); //scale
	SetPosition(Vector3{ 0, 0, 0 }); //location
	mTransform.RotateXInDegrees(90);
	mMeshComponent = new MeshC(this, &Asset::GetMesh("pin"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("Pin_TEX")});

	AddComponent(mMeshComponent);

	mBoxCollider = new BoxCollider3DC(this);
	mBoxCollider->SetCustomSize(Vector3(0.1, 2, 0.1));
	AddComponent(mBoxCollider);

	AddTag("bowlingPin");
}

void PinA::Update()
{
				//NEED DEBUG//
	if (mForce.x != 0 && mForce.y != 0) 
	{
		Log::Info("" + std::to_string(mTransform.GetRotationInDegrees().x) + ", " + std::to_string(mTransform.GetRotationInDegrees().y) + ", " + std::to_string(mTransform.GetRotationInDegrees().z));

		mTransform.RotateXInDegrees(mForce.y);
		mTransform.RotateYInDegrees(mForce.x);
		if (mTransform.GetRotationInDegrees().x < mForce.y || mTransform.GetRotationInDegrees().x > 360 - mForce.y)
		{
			mForce.y = 0;
		}
		if (mTransform.GetRotationInDegrees().y < mForce.x || mTransform.GetRotationInDegrees().y > 360 - mForce.x)
		{
			mForce.y = 0;
		}
	}
				////////////////

	if (mBoxCollider->OnCollide() == true)
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

void PinA::AddForce(Vector3 pForce)
{
	mForce = pForce;
	Vector3 newPos = mTransform.GetPosition() + (pForce * -1);
	newPos.z = 1;
	for (int x = 0; x <= 1000; x++)
	{
		SetPosition(Vector3::Lerp(mTransform.GetPosition(), newPos, 0.0002));
		mTransform.RotateXInDegrees(pForce.y / 1000);
		mTransform.RotateYInDegrees(pForce.x / 1000);
	}
}
