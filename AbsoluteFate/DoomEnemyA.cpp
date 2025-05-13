#include "DoomEnemyA.h"

#include "Asset.h"
#include <iostream>

#include "Log.h"

void DoomEnemyA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Doom/168.png", "DtextDoor");
	Asset::LoadMesh("Resources/3D_Models/cube.obj", "doomDoor");

	//actor
	SetScale(Vector3{ 0.5, 2, 3 }); //scale
	SetPosition(Vector3{ 20, -15, 0.5 }); //location

	//mesh component
	mMeshComponent = new MeshC(this, &Asset::GetMesh("doomDoor"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("DtextDoor")});
	AddComponent(mMeshComponent);

	//box collider
	mBoxCollider = new DoomBoxCollider3DC(this);
	mBoxCollider->SetCustomSize(Vector3(0.5, 1, 1));
	AddComponent(mBoxCollider);

	//change shader
	mTessVertexShader.Load("TessSimpleVert.shader", ShaderType::VERTEX);
	mTessFragShader.Load("TessSimpleFrag.shader", ShaderType::FRAGMENT);
	mTessControlShader.Load("TessSimpleTesc.shader", ShaderType::TESSELLATION_CONTROL);
	mTessEvalShader.Load("TessSimpleTese.shader", ShaderType::TESSELLATION_EVALUATION);

	mTessProgram.Compose({ &mTessVertexShader, &mTessFragShader, &mTessControlShader, &mTessEvalShader });
	mMeshComponent->GetMesh()->SetShaderProgram(mTessProgram);
	mMeshComponent->EnableTesselation();
	mMeshComponent->SetTesselationLevel(10);

	//mMeshComponent->SetTiling({ 4,4 });
	mTransform.RotateZInDegrees(mTransform.GetRotationInDegrees().z - atan2(mTransform.GetPosition().y - mTarget->GetTransform().GetPosition().y, mTransform.GetPosition().x - mTarget->GetTransform().GetPosition().x) * (180 / Maths::PI));
}

void DoomEnemyA::Update()
{
	if (mTarget != nullptr)
	{
		LookAt(mTarget);

		/*if (distance to mTarget)
		{
			Shoot()
		}*/
	}
}

void DoomEnemyA::Destroy()
{
}

void DoomEnemyA::LookAt(Actor* pTarget)
{
	SetRotation(Quaternion(Vector3(0,0,1), atan2(mTransform.GetPosition().y - pTarget->GetTransform().GetPosition().y, mTransform.GetPosition().x - pTarget->GetTransform().GetPosition().x)));
	
			//Debug Angle\\
	//Log::Info(to_string(mTransform.GetRotationInDegrees().z - atan2(mTransform.GetPosition().y - pTarget->GetTransform().GetPosition().y, mTransform.GetPosition().x - pTarget->GetTransform().GetPosition().x) * (180 / Maths::PI)));
}

void DoomEnemyA::Shoot()
{
}
