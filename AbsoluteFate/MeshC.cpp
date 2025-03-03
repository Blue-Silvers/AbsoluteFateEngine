#include "MeshC.h"

#include "Scene.h"
#include "IRenderer.h"
#include "RendererGl.h"
#include "VertexArray.h"

MeshC::MeshC(Actor* pOwner) : Components(pOwner), 
							  mMesh(nullptr), 
							  mTextureIndex(0)
{
	mMesh = new Mesh();
	mOwner->GetScene()->ActiveScene->GetRenderer()->AddMesh(this);
	//Scene::ActiveScene->GetRenderer().AddMesh(this);
}

MeshC::~MeshC()
{
	mOwner->GetScene()->ActiveScene->GetRenderer()->RemoveMesh(this);
	//Scene::ActiveScene->GetRenderer().RemoveMesh(this);
}

void MeshC::Draw(Matrix4Row viewProj)
{
	if (mMesh)
	{
		Matrix4Row wt = mOwner->GetTransform().GetWorldTransform();
		mMesh->GetShaderProgram().Use();
		mMesh->GetShaderProgram().setMatrix4Row("uViewProj", viewProj);
		mMesh->GetShaderProgram().setMatrix4Row("uWorldTransform", wt);
		Texture* t = mMesh->GetTexture(mTextureIndex);
		if (t) t->SetActive();
		mMesh->GetVao()->SetActive();
		glDrawElements(GL_TRIANGLES, mMesh->GetVao()->GetIndicesCount(), GL_UNSIGNED_INT, nullptr);
	}
}

void MeshC::SetMesh(Mesh& pMesh)
{
	mMesh = &pMesh;
}

void MeshC::SetTextureIndex(size_t pTextureIndex)
{
	mTextureIndex = pTextureIndex;
}
