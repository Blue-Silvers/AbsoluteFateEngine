#pragma once
#include <string>
#include <fstream>

enum ShaderType 
{
	VERTEX,
	FRAGMENT,
	TESSELLATION_CONTROL,
	TESSELLATION_EVALUATION,
	GEOMETRY
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

	Shader();
	Shader(int pId, std::string pFile, ShaderType pShaderType);
	~Shader();

	void Load(std::string pFileName, ShaderType pShaderType);
	int GetID() const;
	std::string& GetCode();
};

