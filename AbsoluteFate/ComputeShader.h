#pragma once

#include "RendererGL.h" // Pour accéder aux abstractions de rendu
#include "Matrix4Row.h"
#include "Matrix4.h"
#include "Vector2.h"
#include "Vector3.h"
#include <string>

class ComputeShader {
public:
    ComputeShader(const std::string& filePath);
    ~ComputeShader();

    void Bind() const;
    void Unbind() const;

    // Dispatcher
    void Dispatch(unsigned int x, unsigned int y = 1, unsigned int z = 1) const;

    // Waitter
    static void WaitMemoryBarrier();

    // Uniforms setters
    void setBool(const GLchar* name, bool value);
    void setFloat(const GLchar* name, GLfloat value);
    void setInteger(const GLchar* name, GLint value);
    void setVector2f(const GLchar* name, GLfloat x, GLfloat y);
    void setVector2f(const GLchar* name, const Vector2& value);
    void setVector3f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z);
    void setVector3f(const GLchar* name, const Vector3& value);
    void setVector4f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    void setVector4f(const GLchar* name, const Vector4& value);
    void setMatrix4(const GLchar* name, const Matrix4& matrix);
    void setMatrix4Row(const GLchar* name, const Matrix4Row& matrix);

private:
    unsigned int mId;
    int GetUniformLocation(const std::string& name) const;
    std::string ReadFile(const std::string& filePath);
};