#include "FPSCameraA.h"

#include "Asset.h"
#include <iostream>

#include "Log.h"

void FPSCameraA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/meme.png", "yes");
	Asset::LoadMesh("Resources/3D_Models/Loader_car.obj", "Forklift");
	//Actor
	SetScale(Vector3{ 1, 1, 1 }); //scale
	SetPosition(Vector3{ 0, -4, 0 }); //location

	mMeshComponent = new MeshC(this, &Asset::GetMesh("sphere"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("yes")});

	AddComponent(mMeshComponent);
}

void FPSCameraA::Update()
{
	SDL_GetRelativeMouseState(&mMouseDeltaX, &mMouseDeltaY);

	//don't work//
	if (mMouseDeltaX != 0)
	{
		//Log::Info("" + std::to_string(mMouseDeltaX) + ", " + std::to_string(mMouseDeltaY));
		//mTransform.Rotate(1, Vector3::unitY);
		mTransform.RotateXInDegrees(mMouseDeltaX);
		mTransform.ComputeWorldTransform();
	}
	if (mMouseDeltaY != 0)
	{
		//Log::Info("" + std::to_string(mMouseDeltaX) + ", " + std::to_string(mMouseDeltaY));
		//mTransform.Rotate(1, Vector3::unitY);
		mTransform.RotateYInDegrees(mMouseDeltaY);
		mTransform.ComputeWorldTransform();
	}
	//mTransform.RotateXInDegrees(1);
	mTransform.RotateZInDegrees(1);
	Log::Info("" + std::to_string(mTransform.GetRotation().x) + ", " + std::to_string(mTransform.GetRotation().y) + ", " + std::to_string(mTransform.GetRotation().z));
}

void FPSCameraA::Destroy()
{
}
