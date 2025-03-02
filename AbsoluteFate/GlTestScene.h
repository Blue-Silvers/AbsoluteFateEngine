#pragma once
#include "Scene.h"
class GlTestScene : public Scene
{
public:

	GlTestScene() :Scene("OpenGl") {};
	void SetRenderer(IRenderer* pRenderer) override;
	void Start() override;
	void Update()override;
	void Render() override;
	void  Close() override;
};

