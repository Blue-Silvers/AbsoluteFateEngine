#pragma once
#include "Shader.h"

#include "Matrix4Row.h"
#include "Matrix4.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

#include <glew.h>
#include <vector>

class ShaderProgram
{
private:
	unsigned int mId;

public:
	ShaderProgram();
	~ShaderProgram() = default;
	void Unload();
	void Compose(std::vector<Shader*> shaders);

	unsigned int GetID();
	void Use();
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
};