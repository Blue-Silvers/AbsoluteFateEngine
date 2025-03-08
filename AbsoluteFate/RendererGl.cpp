#include "RendererGl.h"

#include "SpriteC.h"

//Constructor
RendererGl::RendererGl() :  mWindow(nullptr), 
							mSpriteVao(nullptr), 
							mContext(nullptr), 
							mSpriteShaderProgram(nullptr),
							//mSpriteViewProj(Matrix4Row::CreateSimpleViewProj(800, 800)),
							mView(Matrix4Row::CreateLookAt(Vector3(0, 0, 5), Vector3::unitX, Vector3::unitZ)),
							mProj(Matrix4Row::CreatePerspectiveFOV(70.0f, 800, 800, 0.01f, 10000.0f))

{
	mSpriteViewProj = Matrix4Row::CreateSimpleViewProj(800, 800);
}

RendererGl::~RendererGl()
{
	delete mSpriteVao;
}

//Initialize render variable
bool RendererGl::Initialize(Window& rWindow)
{
	mWindow = &rWindow;

	//Setting OpenGL attributes
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

	//8 bits color buffer
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

	mContext = SDL_GL_CreateContext(mWindow->GetSdlWindow());
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		Log::Error(LogType::Video, "Failed to initialize GLEW");
		return false;
	}
	glGetError();

	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		Log::Error(LogType::Video, "Failed to initialize SDL_Image");
	}

	mSpriteVao = new VertexArray(vertices, 4, indices, 6);
	//mSpriteVao = new VertexArray(spriteVertices, 4);
	mSpriteViewProj = Matrix4Row::CreateSimpleViewProj(mWindow->GetDimensions().x, mWindow->GetDimensions().y);

	mView = Matrix4Row::CreateLookAt(Vector3(0, 0, 5), Vector3::unitX, Vector3::unitZ);
	mProj = Matrix4Row::CreatePerspectiveFOV(70.0f, mWindow->GetDimensions().x, mWindow->GetDimensions().y, 0.01f, 10000.0f);

	return true;
}

void RendererGl::SetViewMatrix(Matrix4Row pView)
{
	mView = pView;
}

//Set shader program
void RendererGl::SetShaderProgram(ShaderProgram* pShaderProgram)
{
	mSpriteShaderProgram = pShaderProgram;
}

//Start drawing whith render variable
void RendererGl::BeginDraw()
{
	glClearColor(0.45f, 0.45f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

//Draw all Meshs before all Sprites
void RendererGl::Draw()
{
	DrawAllMeshes();
	DrawAllSprites();
}

void RendererGl::DrawAllSprites()
{
	//draw all sprites in list
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendEquationSeparate(GL_FUNC_ADD, GL_FUNC_ADD);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	if (mSpriteShaderProgram != nullptr) mSpriteShaderProgram->Use();
	mSpriteShaderProgram->setMatrix4Row("uViewProj", mSpriteViewProj);
	mSpriteVao->SetActive();

	for (SpriteC* sprite : mSpritesList)
	{
		if (sprite != nullptr)
		{
			sprite->Draw(*this);
		}
	}

}

//Stop drawing whith render variable
void RendererGl::EndDraw()
{
	SDL_GL_SwapWindow(mWindow->GetSdlWindow());
}

void RendererGl::DrawSprite(Actor& pActor, const Texture& pTex, Rectangle pSourceRect, Vector2 pOrigin, Flip pFlip) const
{
	mSpriteShaderProgram->Use();
	pActor.GetTransform().ComputeWorldTransform();
	Matrix4Row scaleMat = Matrix4Row::CreateScale(  pTex.GetWidth(),
													pTex.GetHeight(),
													0.0f);
	Matrix4Row world = scaleMat * pActor.GetTransform().GetWorldTransform();
	mSpriteShaderProgram->setMatrix4Row("uWorldTransform", world);
	pTex.SetActive();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	//glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void RendererGl::AddSprite(SpriteC* pSprite)
{
	int spriteDrawOrder = pSprite->GetDrawOrder();
	std::vector<SpriteC*>::iterator spriteComponent;
	for (spriteComponent = mSpritesList.begin(); spriteComponent != mSpritesList.end(); ++spriteComponent)
	{
		if (spriteDrawOrder < std::distance(mSpritesList.begin(), spriteComponent)) break;
	}
	mSpritesList.insert(spriteComponent, pSprite);
}

void RendererGl::RemoveSprite(SpriteC* pSprite)
{
	std::vector<SpriteC*>::iterator spriteComponent;
	spriteComponent = std::find(mSpritesList.begin(), mSpritesList.end(), pSprite);
	mSpritesList.erase(spriteComponent);
}

void RendererGl::DrawAllMeshes()
{
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);
	for (MeshC* m : MeshComponentList)
	{
		if(m != nullptr)
		{
			m->Draw(mView * mProj);
		}
	}
}

void RendererGl::AddMesh(MeshC* pMesh)
{
	MeshComponentList.push_back(pMesh);
	//std::vector<MeshC*>::iterator spriteComponent;
	//for (spriteComponent = MeshComponentList.begin(); spriteComponent != MeshComponentList.end(); ++spriteComponent)
	//{
	//	if (MeshComponentList.size() < std::distance(MeshComponentList.begin(), spriteComponent)) break;
	//}
	//MeshComponentList.insert(spriteComponent, pMesh);
}

void RendererGl::RemoveMesh(MeshC* pMesh)
{
	std::vector<MeshC*>::iterator sc;
	sc = std::find(MeshComponentList.begin(), MeshComponentList.end(), pMesh);
	MeshComponentList.erase(sc);
}

//Destroy renderer contain render variable
void RendererGl::Close()
{
	SDL_GL_DeleteContext(mContext);
	delete mSpriteVao;
}

//Get renderer type
IRenderer::RendererType RendererGl::GetType()
{
	return RendererType::OPENGL;
}
