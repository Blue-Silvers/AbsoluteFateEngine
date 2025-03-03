#pragma once

constexpr float vertices[] = {
-0.5f, 0.5f, 0.0f,		//A
0.5f, 0.5f, 0.0f,		//B
0.5f, -0.5f, 0.0f,		//C
-0.5f, -0.5f, 0.0f };	//D

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
	VertexArray(unsigned int pVerticeCount,
				unsigned int pIndexCount);

	VertexArray(const float* pVertices, 
				unsigned int pVerticeCount, 
				const unsigned int* pIndices, 
				unsigned int pIndexCount);
	~VertexArray();

	void SetActive();

	//Getter
	unsigned int GetVerticeCount() const { return mVerticeCount; }
	unsigned int GetIndicesCount() const { return mIndexCount; }
};

