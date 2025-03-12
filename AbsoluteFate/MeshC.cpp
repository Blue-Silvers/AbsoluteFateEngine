#include "MeshC.h"

#include "Scene.h"
#include "IRenderer.h"
#include "RendererGl.h"
#include "VertexArray.h"

#include "Asset.h"

MeshC::MeshC(Actor* pOwner) : Components(pOwner), 
							  mMesh(nullptr), 
							  mTextureIndex(0)
{
	mMesh = new Mesh();
	if (pOwner->GetScene()->GetRenderer()->GetType() == IRenderer::RendererType::OPENGL)
	{
		pOwner->GetScene()->GetRenderer()->AddMesh(this);
	}
	//pOwner->GetScene()->ActiveScene->GetRenderer()->AddMesh(this);
	//Scene::ActiveScene->GetRenderer().AddMesh(this);
}

MeshC::MeshC(Actor* pOwner, Mesh* pMesh) : Components(pOwner),
										  mMesh(nullptr),
										  mTextureIndex(0)
{
	mMesh = pMesh;
	if (pOwner->GetScene()->GetRenderer()->GetType() == IRenderer::RendererType::OPENGL)
	{
		pOwner->GetScene()->GetRenderer()->AddMesh(this);
	}
}

MeshC::~MeshC()
{
	mOwner->GetScene()->ActiveScene->GetRenderer()->RemoveMesh(this);
}

void MeshC::Draw(Matrix4Row viewProj)
{
	if (mMesh != nullptr)
	{
		Matrix4Row wt = mOwner->GetTransform().GetWorldTransform();
		mMesh->GetShaderProgram().Use();
		mMesh->GetShaderProgram().setMatrix4Row("uViewProj", viewProj);
		mMesh->GetShaderProgram().setMatrix4Row("uWorldTransform", wt);

		Texture* t = mMesh->GetTexture(mTextureIndex);
		if (t) 
		{
			t->SetActive();
		}

		mMesh->GetVao()->SetActive();
		glDrawArrays(GL_TRIANGLES, 0, mMesh->GetVao()->GetVerticeCount());
	}
}

void MeshC::SetMesh(Mesh& pMesh)
{
	if (mOwner->GetScene()->GetRenderer()->GetType() == IRenderer::RendererType::OPENGL)
	{
		mOwner->GetScene()->GetRenderer()->RemoveMesh(this);//Delete obselet mesh
	
		mMesh = &pMesh;

		mOwner->GetScene()->GetRenderer()->AddMesh(this);//Add new mesh in renderer queu
	}
}

void MeshC::SetTextureIndex(int pTextureIndex)
{
	mTextureIndex = pTextureIndex;
}
