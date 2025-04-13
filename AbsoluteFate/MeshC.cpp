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

void MeshC::Draw(Matrix4Row pView, Matrix4Row pProj)
{
	if (mMesh != nullptr)
	{
		Matrix4Row wt = mOwner->GetTransform().GetWorldTransform();
		mMesh->GetShaderProgram().Use();
		mMesh->GetShaderProgram().setMatrix4Row("uViewProj", pView * pProj);
		mMesh->GetShaderProgram().setMatrix4Row("uWorldTransform", wt);
		mMesh->GetShaderProgram().setVector2f("uTiling", mTilling);
		mMesh->GetShaderProgram().setVector2f("uOffset", mOffset);
		mMesh->GetShaderProgram().setInteger("uTessLevel", mTessLevel);
		
		//mMesh->GetShaderProgram().setMatrix4Row("uView", pView);
		//mMesh->GetShaderProgram().setMatrix4Row("uProj", pProj);
		mMesh->GetShaderProgram().setFloat("uDinMapDepth", 8.0f);

		Texture* t = mMesh->GetTexture(mTextureIndex);
		if (t) 
		{
			t->SetActive();
		}
		glActiveTexture(GL_TEXTURE1); // active noise texture
		
		if (mMesh->GetNoiseTexture() != nullptr)
		{
			mMesh->GetNoiseTexture()->SetActive();
		}

		mMesh->GetVao()->SetActive();
		glPointSize(5.0f);
		glDrawArrays(mEnableTesselation ? GL_PATCHES : GL_TRIANGLES, 0, mMesh->GetVao()->GetVerticeCount());
		//glDrawArraysInstanced(mEnableTesselation ? GL_PATCHES : GL_TRIANGLES, 0, 3, mMesh->GetVao()->GetVerticeCount());

		glActiveTexture(GL_TEXTURE0); // active color texture
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

void MeshC::AutoTile()
{
	mTilling = (mOwner->GetTransform().GetScale().x, mOwner->GetTransform().GetScale().y);
}

void MeshC::SetTiling(Vector2 pTilling)
{
	mTilling = pTilling;
}

void MeshC::SetOffset(Vector2 pOffset)
{
	mOffset = pOffset;
}