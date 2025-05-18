#include "DoomEnnemyProjectil.h"
#include "DoomPlayerA.h"

void DoomEnnemyProjectil::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Doom/magma.png", "FireBall");
	Asset::LoadMesh("Resources/3D_Models/sphere.obj", "sphereProj");
	//Actor
	SetScale(Vector3{ 1, 1, 1 }); //scale

	mMeshComponent = new MeshC(this, &Asset::GetMesh("sphereProj"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("FireBall")});

	AddComponent(mMeshComponent);

	mBoxCollider = new DoomBoxCollider3DC(this);
	mBoxCollider->SetCustomSize(Vector3(2, 2, 2));
	mBoxCollider->SetIsOverlap(true);
	AddComponent(mBoxCollider);
}

void DoomEnnemyProjectil::Update()
{
	Vector3 newPosition = GetTransform().GetPosition() + ((mForward * mVelocity) * 0.01);
	SetPosition(newPosition);

	for (Components* component : GetAllComponent())
	{
		if (DoomBoxCollider3DC* boxCollider = dynamic_cast<DoomBoxCollider3DC*>(component))
		{
			HitCollider breakHitCollider = boxCollider->GetOnCollide();
			if (breakHitCollider.isCollid == true)
			{
				if (DoomPlayerA* player = dynamic_cast<DoomPlayerA*>(breakHitCollider.collideActor))
				{
					player->TakeDamage();
				}
				bool hit = true;
				for (string tag : breakHitCollider.collideActor->GetTags())
				{
					if (tag == "Enemy") 
					{
						hit = false;
					}
				}
				if (hit == true)
				{
					HitSomething();
				}
			}
		}
	}
}

void DoomEnnemyProjectil::Destroy()
{
}

void DoomEnnemyProjectil::HitSomething()
{
	SetPosition(Vector3{ 0,0,-50 });
	Vector3 mForward = Vector3(0, 0, 0);
}
