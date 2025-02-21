#pragma once
#include "Scene.h"
#include "BigBool.h"

#include "DeathAngelA.h"
class Platformer : public Scene
{
public:


	Platformer() :Scene("Platformer") {};
	void SetRenderer(IRenderer* pRenderer) override;
	void Start() override;
	void Update()override;
	void Render() override;
	void  Close() override;
};

