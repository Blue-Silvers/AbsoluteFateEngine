#pragma once
#include "Mesh.h"
#include "Components.h"

class MeshC : public Components
{
protected:
	Mesh* mMesh;
	int mTextureIndex = 1;
	Vector2 mTilling{ 1,1 };
	Vector2 mOffset{ 1,1 };
	int mTessLevel = 5;
	bool mEnableTesselation = false;

public:
	MeshC(Actor* pOwner);
	MeshC(Actor* pOwner, Mesh* pMesh);
	virtual ~MeshC();
	virtual void Draw(Matrix4Row pView, Matrix4Row pProj);
	virtual void SetMesh(Mesh& pMesh);
	virtual Mesh* GetMesh() { return mMesh; };
	void SetTextureIndex(int pTextureIndex);
	void AutoTile();
	void SetTiling(Vector2 pTilling);
	void SetOffset(Vector2 pOffset);
	inline void EnableTesselation(bool pEnableTesselation = true) { mEnableTesselation = pEnableTesselation; };
	inline void DisableTesselation() { mEnableTesselation = false; };
	inline void SetTesselationLevel(int pTessLevel) { mTessLevel = pTessLevel; };

	void OnStart() override {};
	void Update() override {};
	void OnEnd() override {}
};

