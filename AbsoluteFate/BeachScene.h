#pragma once
#include "Scene.h"
#include "ShaderProgram.h"
#include "Shader.h"
#include "VertexArray.h"

//Actor
#include "CameraA.h"
#include "WaveA.h"
#include "SecondWaveA.h"

class BeachScene : public Scene
{
private:
	Shader mVertexShader;
	Shader mFragmentShader;
	ShaderProgram* mShaderProgram;
	VertexArray mVertexArray;

	//actor
	CameraA* cam;
	WaveA* mWave;
	SecondWaveA* mWaveBack;

public:

	BeachScene() :Scene("OpenGl") {};
	void SetRenderer(IRenderer* pRenderer) override;
	void Start() override;
	void Update()override;
	void Render() override;
	void Close() override;

	inline Shader GetMainVertexShader() { return mVertexShader; };
	inline Shader GetMainFragmentShader() { return mFragmentShader; };
};

