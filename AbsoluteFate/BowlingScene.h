#pragma once
#include "Scene.h"
#include "ShaderProgram.h"
#include "Shader.h"
#include "VertexArray.h"

//Actor.h
#include "CameraBowlingA.h"
#include "BowlingHudA.h"
#include "BowlingBallA.h"
#include "BowlingBorderA.h"
#include "BowlingPathA.h"
#include "PinA.h"
#include "SetOfPinA.h"
#include "BowlingUISkinA.h"

class BowlingScene : public Scene
{
private:
	Shader mVertexShader;
	Shader mFragmentShader;
	ShaderProgram* mShaderProgram;
	VertexArray mVertexArray;

	//actor
	CameraBowlingA* cam;
	BowlingBorderA* rightBorderA;
	BowlingBorderA* leftBorderA;
	BowlingPathA* pathA;
	BowlingHudA* bowlingHudA;
	BowlingBallA* bowlingBallA;
	SetOfPinA* setOfPinA;
	BowlingUISkinA* bowlingUISkinA;

public:

	BowlingScene() :Scene("Bowling") {};
	void SetRenderer(IRenderer* pRenderer) override;
	void Start() override;
	void Update()override;
	void Render() override;
	void Close() override;
};

