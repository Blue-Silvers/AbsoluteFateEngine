#pragma once

constexpr float vertices[] =
{//Coordonate:        Uv pos: R/L   T/B
-0.5f, 0.5f, 0.0f,            0.0f, 0.0f,     //top left
0.5f, 0.5f, 0.0f,             1.0f, 0.0f,     //top right
0.5f, -0.5f, 0.0f,            1.0f, 1.0f,     //bottom right
-0.5f, -0.5f, 0.0f,           0.0f, 1.0f	  //bottom left
};

constexpr float spriteVertices[] = {
	//POSITION                      NORMALS             Uv pos: R/L   T/B
	-0.5f, 0.5f, 0.0f,              0.0f, 0.0f, 0.0f,           0.0f, 0.0f,     //top left
	0.5f, 0.5f, 0.0f,               0.0f, 0.0f, 0.0f,           1.0f, 0.0f,     //top right
	-0.5f, -0.5f, 0.0f,             0.0f, 0.0f, 0.0f,           0.0f, 1.0f,     //bottom left
	0.5f, -0.5f, 0.0f,              0.0f, 0.0f, 0.0f,           1.0f, 1.0f,     //bottom right
};


constexpr unsigned int indices[] = {
0, 1, 2,
2, 3, 0
};

class VertexArray
{
private:
	//Counter
	unsigned int mVerticeCount;
	unsigned int mIndexCount;
	//ID variable
	unsigned int mVertexArrayId;
	unsigned int mVertexBufferId;
	unsigned int mIndexBufferId;
	unsigned int mVboId;

public:
	VertexArray();
	VertexArray(const float* pVertices, 
				unsigned int pVerticeCount, 
				const unsigned int* pIndices, 
				unsigned int pIndexCount);
	VertexArray(const float* pVertices,
				unsigned pVerticeCount);
	~VertexArray();

	void SetActive();

	//Getter
	unsigned int GetVerticeCount() const { return mVerticeCount; }
	unsigned int GetIndicesCount() const { return mIndexCount; }
};

