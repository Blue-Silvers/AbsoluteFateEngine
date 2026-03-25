#pragma once
#include "IRenderer.h"
#include "VertexArray.h"
#include "ShaderProgram.h"

class SpriteC;

enum class MemoryBarrier {
	VertexAttribute = GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT,
	StorageBuffer = GL_SHADER_STORAGE_BARRIER_BIT,
	All = GL_ALL_BARRIER_BITS
};

struct Glyph
{
	Vector2 offset;
	Vector2 advance;
	Vector2 textureCoords;
	Vector2 size;
};

struct RenderData
{
	int fontHeight;
	Glyph glyphs[127];

	vector<ShaderTransform> transforms;
	vector<ShaderTransform> uiTransforms;
};

struct GLContext
{
	GLuint programID;
	GLuint textureID;
	GLuint transformSBOID;
	GLuint materialSBOID;
	GLuint screenSizeID;
	GLuint orthoProjectionID;
	GLuint fontAtlasID;

	long long textureTimestamp;
	long long shaderTimestamp;
};

struct TextData
{
	float fontSize = 1.0f;
	int renderOptions;
	float layer = 0.0f;
};

//OpenGl renderer
class RendererGl : public IRenderer
{
private:
	Window* mWindow;
	VertexArray* mSpriteVao;
	SDL_GLContext mContext;
	ShaderProgram* mSpriteShaderProgram;
	Matrix4Row mView;
	Matrix4Row mProj;

	RenderData* renderData;
	GLContext glContext;

public:
	//Constructor
	RendererGl();
	virtual ~RendererGl();
	RendererGl(const RendererGl&) = delete;
	RendererGl& operator=(const RendererGl&) = delete;

	//Define shader program
	void SetShaderProgram(ShaderProgram* pShaderProgram);

					//Base fonction//
	bool Initialize(Window& rWindow) override;
	void SetViewMatrix(Matrix4Row pView) override;
	//Draw fonction
	void BeginDraw() override;
	void Draw() override;
	void DrawAllSprites() override;
	void EndDraw() override;
	//Draw Sprites
	void DrawSprite(Actor& pActor, const Texture& pTex, Rectangle pSourceRect, Vector2 pOrigin, Flip pFlip = Flip::None) const override;
	void AddSprite(SpriteC* pSprite) override;
	void RemoveSprite(SpriteC* pSprite) override;
	//Draw Meshs
	void DrawAllMeshes() override;
	void AddMesh(MeshC* pMesh) override;
	void RemoveMesh(MeshC* pMesh) override;
	//Close
	void Close() override;
	//Getter
	RendererType GetType() override;
	Matrix4Row GetProj() override { return mProj; }

	//Compute shader
	static void Wait(MemoryBarrier barrier);
	void DispatchCompute(unsigned int numGroupsX, unsigned int numGroupsY = 1, unsigned int numGroupsZ = 1);
	void BindBufferBase(unsigned int slot, unsigned int bufferID);
};