#pragma once

#include "Scene.h"
#include "Texture.h"

#include "Scene.h"
#include "ShaderProgram.h"
#include "Shader.h"
#include "VertexArray.h"

class CubeScene : public Scene
{
private:
    Shader mVertexShader, mFragmentShader, mTessControlShader, mTessEvalShader;
    ShaderProgram mSimpleProgram;
    ShaderProgram tessTest;
public:
    CubeScene();
    ~CubeScene() override = default;
    void Start() override;
    void Render() override;
    void Update() override;
    void Close() override;
};

