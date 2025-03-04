#pragma once
#include "Mesh.h"
#include "Components.h"

class MeshC : public Components
{
protected:
	Mesh* mMesh;
	size_t mTextureIndex;

public:
	MeshC(Actor* pOwner);
	virtual ~MeshC();
	virtual void Draw(Matrix4Row viewProj);
	virtual void SetMesh(Mesh& pMesh);
	void SetTextureIndex(size_t pTextureIndex);
};

