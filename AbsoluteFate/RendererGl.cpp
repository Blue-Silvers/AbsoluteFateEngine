#include "RendererGl.h"

#include "SpriteC.h"
#include"AnimatedSpriteC.h"
#include "Asset.h"

// To Load TTF Files
#include <ft2build.h>
#include FT_FREETYPE_H
#include "Maths.h"

//Constructor
RendererGl::RendererGl() :  mWindow(nullptr), 
							mSpriteVao(nullptr), 
							mContext(nullptr), 
							mSpriteShaderProgram(nullptr),
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

	mSpriteVao = new VertexArray(spriteVertices, 4);
	mSpriteViewProj = Matrix4Row::CreateSimpleViewProj(mWindow->GetDimensions().x, mWindow->GetDimensions().y);

	mView = Matrix4Row::CreateLookAt(Vector3(0, 0, 5), Vector3::unitX, Vector3::unitZ);
	mProj = Matrix4Row::CreatePerspectiveFOV(70.0f, mWindow->GetDimensions().x, mWindow->GetDimensions().y, 0.01f, 10000.0f);

	glPatchParameteri(GL_PATCH_VERTICES, 3);

	load_font((char*)"Resources/Fonts/AtariClassic-gry3.ttf", 8);

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

		if (AnimatedSpriteC* animatedSprite = dynamic_cast<AnimatedSpriteC*>(sprite))
		{
			animatedSprite->Update();
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
	mSpriteShaderProgram->setVector2f("uTiling", (1, 1));
	pTex.SetActive();

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
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
			m->Draw(mView, mProj);
		}
	}
}

void RendererGl::AddMesh(MeshC* pMesh)
{
	MeshComponentList.push_back(pMesh);
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

void RendererGl::load_font(char* filePath, int fontSize)
{
	FT_Library fontLibrary;
	FT_Init_FreeType(&fontLibrary);

	FT_Face fontFace = FT_Face();
	FT_New_Face(fontLibrary, filePath, 0, &fontFace);
	FT_Set_Pixel_Sizes(fontFace, 0, fontSize);

	int padding = 2;
	int row = 0;
	int col = padding;

	const int textureWidth = 512;
	char textureBuffer[textureWidth * textureWidth];
	for (FT_ULong glyphIdx = 32; glyphIdx < 127; ++glyphIdx)
	{
		FT_UInt glyphIndex = FT_Get_Char_Index(fontFace, glyphIdx);
		FT_Load_Glyph(fontFace, glyphIndex, FT_LOAD_DEFAULT);
		FT_Error error = FT_Render_Glyph(fontFace->glyph, FT_RENDER_MODE_NORMAL);

		if (col + fontFace->glyph->bitmap.width + padding >= 512)
		{
			col = padding;
			row += fontSize;
		}

		// Font Height
		renderData->fontHeight = Maths::max((fontFace->size->metrics.ascender - fontFace->size->metrics.descender) >> 6, renderData->fontHeight);
		for (unsigned int y = 0; y < fontFace->glyph->bitmap.rows; ++y)
		{
			for (unsigned int x = 0; x < fontFace->glyph->bitmap.width; ++x)
			{
				textureBuffer[(row + y) * textureWidth + col + x] =
					fontFace->glyph->bitmap.buffer[y * fontFace->glyph->bitmap.width + x];
			}
		}

		Glyph* glyph = &renderData->glyphs[glyphIdx];
		glyph->textureCoords = { (float)col, (float)row };
		glyph->size =
		{
		  (float)fontFace->glyph->bitmap.width,
		  (float)fontFace->glyph->bitmap.rows
		};
		glyph->advance =
		{
		  (float)(fontFace->glyph->advance.x >> 6),
		  (float)(fontFace->glyph->advance.y >> 6)
		};
		glyph->offset =
		{
		  (float)fontFace->glyph->bitmap_left,
		  (float)fontFace->glyph->bitmap_top,
		};

		col += fontFace->glyph->bitmap.width + padding;
	}

	FT_Done_Face(fontFace);
	FT_Done_FreeType(fontLibrary);

	// Upload OpenGL Texture
	{
		glGenTextures(1, (GLuint*)&glContext.fontAtlasID);
		glActiveTexture(GL_TEXTURE1); // Bound to binding = 1, see SpriteFrag.shader
		glBindTexture(GL_TEXTURE_2D, glContext.fontAtlasID);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_R8, textureWidth, textureWidth, 0,
			GL_RED, GL_UNSIGNED_BYTE, (char*)textureBuffer);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
}

void RendererGl::draw_ui_text(char* text, Vector2 pos, TextData textData = {})
{
	if (!text)
	{
		return;
	}

	Vector2 origin = pos;
	while (char c = *(text++))
	{
		if (c == '\n')
		{
			pos.y += renderData->fontHeight * textData.fontSize;
			pos.x = origin.x;
			continue;
		}

		Glyph glyph = renderData->glyphs[c];
		ShaderTransform transform = {};
		transform.materialIdx = get_material_idx(textData.material);
		transform.pos.x = pos.x + glyph.offset.x * textData.fontSize;
		transform.pos.y = pos.y - glyph.offset.y * textData.fontSize;
		transform.atlasOffset = glyph.textureCoords;
		transform.spriteSize = glyph.size;
		transform.size = glyph.size * textData.fontSize;
		transform.renderOptions = textData.renderOptions | RENDERING_OPTION_FONT;
		transform.layer = textData.layer;

		renderData->uiTransforms.push_back(transform);

		// Advance the Glyph
		pos.x += glyph.advance.x * textData.fontSize;
	}
}

int RendererGl::get_material_idx(Material material = {})
{
	// Convert from SRGB to linear color space, to be used in the shader, poggies
	material.color.x = powf(material.color.x, 2.2f);
	material.color.y = powf(material.color.y, 2.2f);
	material.color.z = powf(material.color.z, 2.2f);
	material.color.w = powf(material.color.w, 2.2f);

	for (int materialIdx = 0; materialIdx < renderData->materials.size(); materialIdx++)
	{
		if (renderData->materials[materialIdx] == &material)
		{
			return materialIdx;
		}
	}
	renderData->materials.push_back(&material);
	return 0;
}
//https://youtu.be/23x0nGzHQgY?si=7uZus4COJtWPWxut&t=1008