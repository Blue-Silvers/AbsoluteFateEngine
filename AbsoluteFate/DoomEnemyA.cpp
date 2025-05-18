#include "DoomEnemyA.h"

#include "Asset.h"
#include <iostream>

#include "Log.h"

void DoomEnemyA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/theBlock.png", "DtextEn");
	Asset::LoadMesh("Resources/3D_Models/cube.obj", "doomDEn");

	//actor
	SetScale(Vector3{ 0.5, 2, 3 }); //scale
	SetPosition(Vector3{ 20, -15, 0.5 }); //location

	//mesh component
	mMeshComponent = new MeshC(this, &Asset::GetMesh("doomDEn"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("DtextEn")});
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

	mMeshComponent->SetTiling({ 3,4 });
	mMeshComponent->SetOffset({ 1,1 });
	mTransform.RotateZInDegrees(mTransform.GetRotationInDegrees().z - atan2(mTransform.GetPosition().y - mTarget->GetTransform().GetPosition().y, mTransform.GetPosition().x - mTarget->GetTransform().GetPosition().x) * (180 / Maths::PI));
	
	AddTag("Enemy");
}

void DoomEnemyA::Restart()
{
	mLife = 2;
	SetPosition(Vector3{ 20, -15, 0.5 });
}

void DoomEnemyA::Update()
{
	if (mTarget != nullptr)
	{
		LookAt(mTarget);

		
		float calculateDistance = std::sqrt(std::pow(mTarget->GetTransform().GetPosition().x - GetTransform().GetPosition().x, 2) + std::pow(mTarget->GetTransform().GetPosition().y - GetTransform().GetPosition().y, 2));
		if (calculateDistance <= mShootingRange && mCanShootAgain == true)
		{
			mCanShootAgain = false;
			Shoot();
			mActualShootCooldown = mShootCooldown;
		}
		if (mCanShootAgain == false) 
		{
			mActualShootCooldown -= 1;
			if (mActualShootCooldown <= 0) 
			{
				mCanShootAgain = true;
			}
		}
	}
	for (DoomEnnemyProjectil* projectil : mCurrentProjectils)
	{
		projectil->Update();
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
	DoomEnnemyProjectil* newProj = new DoomEnnemyProjectil();
	newProj->AttachScene(GetScene());
	mCurrentProjectils.push_back(newProj);

	newProj->Start();

	newProj->SetPosition(mTransform.GetPosition());
	newProj->SetForward(mTransform.Forward() * -1);
}

void DoomEnemyA::TakeDamage()
{
	mLife -= 1;
	Log::Info("HIIIIIIIIIIIIIIIIIIIIIIIIIIT");
	if (mLife <= 0) 
	{
		SetPosition(Vector3{ 0, 0, -50 });
	}
}
