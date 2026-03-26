#pragma once
#include "Scene.h"
#include "ShaderProgram.h"
#include "Shader.h"
#include "VertexArray.h"
#include "ComputeShader.h"
#include "Vector2.h"
#include "Vector4.h"

struct Particle {
	Vector2 pos;
	Vector2 vel;
	Vector4 color;
};

class ComputeShaderScene : public Scene
{
private:
	ComputeShader* mComputeShader;
	unsigned int mParticleCount = 100000;
	unsigned int mSSBO;
	unsigned int mVAO;

	// Shader
	ShaderProgram* mShaderProgram;
	Shader mVertexShader;
	Shader mFragmentShader;

	//Uniforms data
	float mTotalTime = 0.0f;
	int mMouseX, mMouseY = 0;
	int mWindowWidth, mWindowHeight = 0;
	Uint32 mMouseState = 0;
	float mNdcX = 0.0f;
	float mNdcY = 0.0f;
	Vector2 mMousePos = { 0.0f, 0.0f };
	bool mIsLeftClicking = false;
	bool mIsRightClicking = false;

public:
	ComputeShaderScene() :Scene("OpenGl") {};
	void SetRenderer(IRenderer* pRenderer) override;
	void Start() override;
	void Update()override;
	void Render() override;
	void Close() override;

	inline Shader GetMainVertexShader() { return mVertexShader; };
	inline Shader GetMainFragmentShader() { return mFragmentShader; };
};