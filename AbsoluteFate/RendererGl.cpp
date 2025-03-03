#include "RendererGl.h"

#include "SpriteC.h"

RendererGl::RendererGl() : mWindow(nullptr), mVao(nullptr), mContext(nullptr), mShaderProgram(0), mSprites({nullptr}), mViewProj()
{
}

RendererGl::~RendererGl()
{
	delete mVao;
}

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

	mVao = new VertexArray(vertices, 4, indices, 6);
	mViewProj = Matrix4Row::CreateSimpleViewProj(mWindow->GetDimensions().x, mWindow->GetDimensions().y);
	return true;
}

void RendererGl::SetShaderProgram(ShaderProgram* pShaderProgram)
{
	mShaderProgram = pShaderProgram;
}

void RendererGl::BeginDraw()
{
	glClearColor(0.45f, 0.45f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	if (mShaderProgram != nullptr)
	{
		mShaderProgram->Use();
	}
	mShaderProgram->setMatrix4Row("uViewProj", mViewProj);
	mVao->SetActive();
}

void RendererGl::Draw()
{
}

void RendererGl::DrawAllSprites()
{
}

void RendererGl::EndDraw()
{
	SDL_GL_SwapWindow(mWindow->GetSdlWindow());
}

void RendererGl::DrawSprite(Actor& pActor, const Texture& pTex, Rectangle pSourceRect, Vector2 pOrigin, Flip pFlip) const
{
	mShaderProgram->Use();
	pActor.GetTransform().ComputeWorldTransform();
	Matrix4Row scaleMat = Matrix4Row::CreateScale(  pTex.GetWidth(),
													pTex.GetHeight(),
													0.0f);
	Matrix4Row world = scaleMat * pActor.GetTransform().GetWorldTransform();
	mShaderProgram->setMatrix4Row("uWorldTransform", world);
	pTex.SetActive();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

void RendererGl::AddSprite(SpriteC* pSprite)
{
	int spriteDrawOrder = pSprite->GetDrawOrder();
	std::vector<SpriteC*>::iterator sc;
	for (sc = mSprites.begin(); sc != mSprites.end(); ++sc)
	{
		if (spriteDrawOrder < (*sc)->GetDrawOrder()) break;
	}
	mSprites.insert(sc, pSprite);
}

void RendererGl::RemoveSprite(SpriteC* pSprite)
{
	std::vector<SpriteC*>::iterator sc;
	sc = std::find(mSprites.begin(), mSprites.end(), pSprite);
	mSprites.erase(sc);
}

void RendererGl::Close()
{
	SDL_GL_DeleteContext(mContext);
	delete mVao;
}

IRenderer::RendererType RendererGl::GetType()
{
	return RendererType::OPENGL;
}
