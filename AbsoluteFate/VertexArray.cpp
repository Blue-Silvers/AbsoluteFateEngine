#include "VertexArray.h"
#include "Log.h"
#include <glew.h>

VertexArray::VertexArray() :
	mVerticeCount(0), mIndexCount(0), mVertexArrayId(0), mVboId(0), mIndexBufferId(0)
{
}
VertexArray::VertexArray(const float* pVertices, unsigned pVerticeCount) :
	mVerticeCount(pVerticeCount), mVertexArrayId(0), mVboId(0)
{
	//Generate VAO
	glGenVertexArrays(1, &mVertexArrayId);
	glBindVertexArray(mVertexArrayId);

	//Generate VBO
	glGenBuffers(1, &mVboId);
	glBindBuffer(GL_ARRAY_BUFFER, mVboId);
	glBufferData(GL_ARRAY_BUFFER, mVerticeCount * 8 * sizeof(float), pVertices, GL_STATIC_DRAW);

	//Position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)0);
	//Normal
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(sizeof(float) * 3));
	//Texture coordinates
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(sizeof(float) * 6));
}

VertexArray::VertexArray(const float* pVertices, unsigned int pVerticeCount, const unsigned int* pIndices, unsigned int pIndexCount) :
	mVerticeCount(pVerticeCount), mIndexCount(pIndexCount), mVertexArrayId(0), mVboId(0), mIndexBufferId(0)
{
	//Generate VAO
	glGenVertexArrays(1, &mVertexArrayId);
	glBindVertexArray(mVertexArrayId);

	//Generate VBO
	glGenBuffers(1, &mVboId);
	glBindBuffer(GL_ARRAY_BUFFER, mVboId);
	glBufferData(GL_ARRAY_BUFFER, mVerticeCount * 5 * sizeof(float), pVertices, GL_STATIC_DRAW);

	//Generate Index Buffer
	glGenBuffers(1, &mIndexBufferId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBufferId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mIndexCount * sizeof(float), pIndices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)(sizeof(float) * 3));
}


VertexArray::~VertexArray()
{
	glDeleteBuffers(1, &mVertexBufferId);
	glDeleteBuffers(1, &mIndexBufferId);
	glDeleteBuffers(1, &mVertexArrayId);
}

void VertexArray::SetActive()
{
	glBindVertexArray(mVertexArrayId);
}