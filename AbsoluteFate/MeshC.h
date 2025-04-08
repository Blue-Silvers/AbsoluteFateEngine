#pragma once
#include "Mesh.h"
#include "Components.h"

class MeshC : public Components
{
protected:
	Mesh* mMesh;
	int mTextureIndex = 1;
	Vector2 mTilling{ 1,1 };
	bool mEnableTesselation = false;

public:
	MeshC(Actor* pOwner);
	MeshC(Actor* pOwner, Mesh* pMesh);
	virtual ~MeshC();
	virtual void Draw(Matrix4Row viewProj);
	virtual void SetMesh(Mesh& pMesh);
	virtual Mesh* GetMesh() { return mMesh; };
	void SetTextureIndex(int pTextureIndex);
	void AutoTile();
	void SetTiling(Vector2 pTilling);
	inline void EnableTesselation() { mEnableTesselation = true; };
	inline void DisableTesselation() { mEnableTesselation = false; };

	void OnStart() override {};
	void Update() override {};
	void OnEnd() override {}
};

