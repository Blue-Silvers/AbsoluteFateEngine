#pragma once
#include <string>
#include <fstream>
#include "Color.h"
#include "Vector2.h"
#include "Vector4.h"

/*#define BIT(i) 1 << i

// #############################################################################
//                           Rendering Constants
// #############################################################################
int RENDERING_OPTION_FLIP_X = BIT(0);
int RENDERING_OPTION_FLIP_Y = BIT(1);
int RENDERING_OPTION_FONT = BIT(2);*/

enum ShaderType 
{
	VERTEX,
	FRAGMENT,
	TESSELLATION_CONTROL,
	TESSELLATION_EVALUATION,
	GEOMETRY
};

//Struct of Transform information for Shader
struct ShaderTransform
{
	Vector2 pos; // This is currently the Top Left!!
	Vector2 size;
	Vector2 atlasOffset;
	Vector2 spriteSize;
	int renderOptions;
	int materialIdx;
	float layer;
	int padding;
};

class Shader
{
protected:
	std::string mCode;
	unsigned int mId;
	ShaderType mType;

public:
	//For change the shader path
	static const std::string SHADER_PATH;

	//Constructor
	Shader();
	Shader(int pId, std::string pFile, ShaderType pShaderType);
	~Shader();

	void Load(std::string pFileName, ShaderType pShaderType);

	//Getters
	int GetID() const;
	std::string& GetCode();
};