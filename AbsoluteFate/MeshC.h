#pragma once
#include "Mesh.h"
#include "Components.h"

class MeshC : public Components
{
protected:
	Mesh* mMesh;
	int mTextureIndex = 1;

public:
	MeshC(Actor* pOwner);
	virtual ~MeshC();
	virtual void Draw(Matrix4Row viewProj);
	virtual void SetMesh(Mesh& pMesh);
	void SetTextureIndex(int pTextureIndex);

	void OnStart() override {};
	void Update() override {};
	void OnEnd() override {}
};

