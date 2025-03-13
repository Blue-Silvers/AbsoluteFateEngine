#pragma once
#include "Scene.h"
#include "ShaderProgram.h"
#include "Shader.h"
#include "VertexArray.h"

//Actor.h
#include "PlaneTextureOpenGlA.h"
#include "BowlingBallA.h"
#include "CameraA.h"
#include "CubeTestA.h"
#include "SphereTestA.h"

class BowlingScene : public Scene
{
private:
	Shader mVertexShader;
	Shader mFragmentShader;
	ShaderProgram* mShaderProgram;
	VertexArray mVertexArray;

	//actor
	CameraA* cam;
	SphereTestA* sphereTestA2;
	SphereTestA* sphereTestA;
	CubeTestA* cubeTestA;
	PlaneTextureOpenGlA* planeTextureOpenGlA;
	BowlingBallA* bowlingBallA;

public:

	BowlingScene() :Scene("Bowling") {};
	void SetRenderer(IRenderer* pRenderer) override;
	void Start() override;
	void Update()override;
	void Render() override;
	void Close() override;
};

