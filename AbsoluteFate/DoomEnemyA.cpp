#include "DoomEnemyA.h"

#include "Asset.h"
#include <iostream>

#include "Log.h"

void DoomEnemyA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Doom/tn397.png", "DtextEn");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Doom/396.png", "DtextEnHit");
	Asset::LoadMesh("Resources/3D_Models/sphere.obj", "doomMeshEn");

	//actor
	SetScale(Vector3{ 0.1F, 3, 3 }); //scale
	SetPosition(Vector3{ 20, -15, 0.5F }); //location

	//mesh component
	mMeshComponent = new MeshC(this, &Asset::GetMesh("doomMeshEn"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("DtextEn")});
	AddComponent(mMeshComponent);

	//box collider
	mBoxCollider = new DoomBoxCollider3DC(this);
	mBoxCollider->SetCustomSize(Vector3(1, 1, 1));
	AddComponent(mBoxCollider);

	//change shader
	mTessVertexShader.Load("TransformVert.shader", ShaderType::VERTEX);
	mTessFragShader.Load("BasicFrag.shader", ShaderType::FRAGMENT);
	mTessProgram.Compose({ &mTessVertexShader, &mTessFragShader});
	mMeshComponent->GetMesh()->SetShaderProgram(mTessProgram);

	mMeshComponent->SetTiling({ 2,1 });
	mMeshComponent->SetOffset({ 0.5,1 });

	
	mTransform.RotateZInDegrees(mTransform.GetRotationInDegrees().z - atan2(mTransform.GetPosition().y - mTarget->GetTransform().GetPosition().y, mTransform.GetPosition().x - mTarget->GetTransform().GetPosition().x) * (180 / Maths::PI));
	AddTag("Enemy");
}

void DoomEnemyA::Restart() 
{
	mLife = 3;
	SetPosition(Vector3{ 20, -15, 0.5 });
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("DtextEn")});

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

	if (mHitAnimTime != 20) 
	{
		mHitAnimTime -= 1;
		if(mHitAnimTime <= 0)
		{
			mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("DtextEn")});
			mHitAnimTime = 20;
		}
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
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("DtextEnHit")});
	mHitAnimTime -= 1;

	if (mLife <= 0) 
	{
		SetPosition(Vector3{ 0, 0, -50 });
	}

}
