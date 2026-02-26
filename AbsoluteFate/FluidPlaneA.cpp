#include "FluidPlaneA.h"

#include "Asset.h"
#include <iostream>
#include "Shader.h"

void FluidPlaneA::Start()
{
	//Load texture
	//Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Fea.png", "White");
	//Asset::LoadMesh("Resources/3D_Models/plane.obj", "Plane");

	////Actor
	//SetScale(Vector3{ 0.01, 0.01, 0.01 }); //scale
	//SetPosition(Vector3{ 50, 50, 0 }); //location

	////Mesh component
	//mMeshComponent = new MeshC(this, &Asset::GetMesh("Plane"));
	//mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("White")});
	//AddComponent(mMeshComponent);

	/**///load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/white.png", "White");;

	Asset::LoadMesh("Resources/3D_Models/plane.obj", "fluidePlane");
	//Actor
	SetScale(Vector3{ 1, 1, 1 }); //scale
	SetPosition(Vector3{ 0, 0, 0 }); //location
	mTransform.RotateYInDegrees(-90);

	//Mesh component
	mMeshComponent = new MeshC(this, &Asset::GetMesh("fluidePlane"));
	mMeshComponent->GetMesh()->SetTextureList(vector<Texture*>{&Asset::GetTexture("White")});
	AddComponent(mMeshComponent);

	//change shader
	/*mTessVertexShader.Load("TessSimpleVert.shader", ShaderType::VERTEX);
	mTessFragShader.Load("TessSimpleFrag.shader", ShaderType::FRAGMENT);
	mTessControlShader.Load("TessSimpleTesc.shader", ShaderType::TESSELLATION_CONTROL);
	mTessEvalShader.Load("TessSimpleTese.shader", ShaderType::TESSELLATION_EVALUATION);

	mTessProgram.Compose({ &mTessVertexShader, &mTessFragShader, &mTessControlShader, &mTessEvalShader });
	mMeshComponent->GetMesh()->SetShaderProgram(mTessProgram);
	mMeshComponent->EnableTesselation();
	mMeshComponent->SetTesselationLevel(1);

	mTessVertexShader.Load("TransformVert.shader", ShaderType::VERTEX);
	mTessFragShader.Load("SpriteFrag.shader", ShaderType::FRAGMENT);*/

	mTessProgram.Compose({ &mTessVertexShader , &mTessFragShader });

	mMeshComponent->GetMesh()->SetShaderProgram(mTessProgram);

	mMeshComponent->AutoTile();
	/**/
	
	/*
	// Load shaders
	mVertexShader.Load("FluidFullscreenVert.shader", ShaderType::VERTEX);
	mAdvectShader.Load("FluidAdvectFrag.shader", ShaderType::FRAGMENT);
	mDivergenceShader.Load("FluidDivergenceFrag.shader", ShaderType::FRAGMENT);
	mPressureShader.Load("FluidPressureFrag.shader", ShaderType::FRAGMENT);
	mProjectionShader.Load("FluidProjectionFrag.shader", ShaderType::FRAGMENT);
	mAddForceShader.Load("FluidAddForceFrag.shader", ShaderType::FRAGMENT);

	// Compose programs
	mAdvectProgram.Compose({ &mVertexShader, &mAdvectShader });
	mDivergenceProgram.Compose({ &mVertexShader, &mDivergenceShader });
	mPressureProgram.Compose({ &mVertexShader, &mPressureShader });
	mProjectionProgram.Compose({ &mVertexShader, &mProjectionShader });
	mAddForceProgram.Compose({ &mVertexShader, &mAddForceShader });*/

	//mMeshComponent->GetMesh()->SetShaderProgram(mAdvectProgram);

	//mMeshComponent->AutoTile();

	//Update shader uniform
	/*mMeshComponent->GetMesh()->GetShaderProgram().setFloat("uDisplacement", mDisplacement);
	mMeshComponent->GetMesh()->GetShaderProgram().setFloat("uAmplitude", mAmplitude);
	mMeshComponent->GetMesh()->GetShaderProgram().setFloat("uFrequency", mFrequency);
	mMeshComponent->GetMesh()->GetShaderProgram().setFloat("uSpeed", mSpeed);
	mMeshComponent->GetMesh()->GetShaderProgram().setBool("uRightClamp", true);
	mMeshComponent->GetMesh()->GetShaderProgram().setVector3f("uLightDir", 80, 20, 20);
	mMeshComponent->GetMesh()->GetShaderProgram().setVector2f("uNormalTiling", 0.5, 0.5);
	mMeshComponent->GetMesh()->GetShaderProgram().setFloat("uNormalStrength", 0.5);*/
}

void FluidPlaneA::Update()
{
}

void FluidPlaneA::Destroy()
{
}
