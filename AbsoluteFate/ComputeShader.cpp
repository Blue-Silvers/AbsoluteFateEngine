#include "ComputeShader.h"

#include <fstream>
#include <sstream>
#include <iostream>

ComputeShader::ComputeShader(const std::string& filePath) {
    std::string source = ReadFile(filePath);
    const char* src = source.c_str();

    unsigned int shader = glCreateShader(GL_COMPUTE_SHADER);
    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::COMPUTE_SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    mId = glCreateProgram();
    glAttachShader(mId, shader);
    glLinkProgram(mId);

    glDeleteShader(shader);
}

ComputeShader::~ComputeShader() {
    glDeleteProgram(mId);
}

void ComputeShader::Bind() const {
    glUseProgram(mId);
}

void ComputeShader::Unbind() const {
    glUseProgram(0);
}

void ComputeShader::Dispatch(unsigned int x, unsigned int y, unsigned int z) const {
    glDispatchCompute(x, y, z);
}

void ComputeShader::WaitMemoryBarrier() {

    glMemoryBarrier(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT | GL_SHADER_STORAGE_BARRIER_BIT);
}

int ComputeShader::GetUniformLocation(const std::string& name) const {
    return glGetUniformLocation(mId, name.c_str());
}

void ComputeShader::setBool(const GLchar* name, bool value)
{
    glUniform1f(GetUniformLocation(name), value);
}

void ComputeShader::setFloat(const GLchar* name, GLfloat value)
{
    glUniform1f(GetUniformLocation(name), value);
}

void ComputeShader::setInteger(const GLchar* name, GLint value)
{
    glUniform1i(GetUniformLocation(name), value);
}

void ComputeShader::setVector2f(const GLchar* name, GLfloat x, GLfloat y)
{
    glUniform2f(GetUniformLocation(name), x, y);
}

void ComputeShader::setVector2f(const GLchar* name, const Vector2& value)
{
    glUniform2f(GetUniformLocation(name), value.x, value.y);
}

void ComputeShader::setVector3f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z)
{
    glUniform3f(GetUniformLocation(name), x, y, z);
}

void ComputeShader::setVector3f(const GLchar* name, const Vector3& value)
{
    glUniform3f(GetUniformLocation(name), value.x, value.y, value.z);
}

void ComputeShader::setVector4f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    glUniform4f(GetUniformLocation(name), x, y, z, w);
}

void ComputeShader::setVector4f(const GLchar* name, const Vector4& value)
{
    glUniform4f(GetUniformLocation(name), value.x, value.y, value.z, value.w);
}

void ComputeShader::setMatrix4(const GLchar* name, const Matrix4& matrix)
{
    glUniformMatrix4fv(GetUniformLocation(name), 1, GL_TRUE, matrix.GetAsFloatPtr());
}

void ComputeShader::setMatrix4Row(const GLchar* name, const Matrix4Row& matrix)
{
    glUniformMatrix4fv(GetUniformLocation(name), 1, GL_TRUE, matrix.GetAsFloatPtr());
}

std::string ComputeShader::ReadFile(const std::string& filePath) {
    std::ifstream file(filePath);
    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}