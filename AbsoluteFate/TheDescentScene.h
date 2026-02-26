#include "Scene.h"
#include "ShaderProgram.h"
#include "Shader.h"
#include "VertexArray.h"

//Actor.h
#include "TheDescentPlayerA.h"

#include "DoomLevel.h"
#include "DoomDoor.h"
#include "DoomLever.h"
#include "DoomEnemyA.h"

class TheDescentScene : public Scene
{
private:
	Shader mVertexShader;
	Shader mFragmentShader;
	ShaderProgram* mShaderProgram;
	VertexArray mVertexArray;

	//actor
	TheDescentPlayerA* mPlayer;
	DoomLevel* mLevel;
	DoomDoor* mDoor;
	DoomLever* mLever;
	DoomEnemyA* mEnemy01;
	DoomEnemyA* mEnemy02;

public:

	TheDescentScene() :Scene("OpenGl") {};
	void SetRenderer(IRenderer* pRenderer) override;
	void Start() override;
	void Retart();
	void Update()override;
	void Render() override;
	void Close() override;

	inline Shader GetMainVertexShader() { return mVertexShader; };
	inline Shader GetMainFragmentShader() { return mFragmentShader; };
};