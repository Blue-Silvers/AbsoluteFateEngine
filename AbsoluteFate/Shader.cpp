#include "Shader.h"
#include "RendererGl.h"
#include "Log.h"

const std::string Shader::SHADER_PATH = {""};

Shader::Shader() : mId(0), 
				   mCode(""), 
				   mType(VERTEX)
{

}

Shader::Shader(int pId, std::string pFile, ShaderType pShaderType) : mId(pId), 
																	 mCode(pFile), 
																	 mType(pShaderType)
{

}

Shader::~Shader()
{

}

void Shader::Load(std::string pFileName, ShaderType pShaderType)
{
    mType = pShaderType;
    std::ifstream myFile;
    myFile.open(SHADER_PATH + pFileName);
    if (myFile.fail()) 
    {
        Log::Error(LogType::Video, "Error - failed to open " + pFileName);;
    }
    std::string fileText = "";
    std::string line = "";

    while (getline(myFile, line)) 
    {
        fileText += line + '\n';
    }

    myFile.close();
    mCode = fileText;

    switch (mType)
    {
        case VERTEX: 
        {
            mId = glCreateShader(GL_VERTEX_SHADER);
            break;
        }
    case FRAGMENT: 
        {
            mId = glCreateShader(GL_FRAGMENT_SHADER);
            break;
        }
    case TESSELLATION_CONTROL:
    {
        break;
    }
    case TESSELLATION_EVALUATION:
    {
        break;
    }
    case GEOMETRY:
    {
        break;
    }
    default:
        {
            Log::Error(LogType::Render, "This shader type has not yet been implemented.");
            mId = glCreateShader(GL_VERTEX_SHADER);
            break;
        }
    }
    const char* source = mCode.c_str();
    glShaderSource(mId, 1, &source, NULL);
    glCompileShader(mId);

}

int Shader::GetID() const
{
	return mId;
}

std::string& Shader::GetCode()
{
	return mCode;
}
