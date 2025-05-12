#include "DoomHudA.h"

#include "SpriteC.h"
#include <iostream>

void DoomHudA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Doom/heartDoom.png", "heartDoom");

	//Icon
	mIconList.push_back(new OpenGlPictureA());
	mIconList.push_back(new OpenGlPictureA());
	mIconList.push_back(new OpenGlPictureA());
	for (Actor* actor : mIconList)
	{
		actor->AttachScene(GetScene());
		actor->Start();
		actor->SetScale2D(Vector2{ 0.45, 0.45 });
	}

	mIconList[0]->SetPosition2D(Vector2{ -150, 350 }); //150px between two icon
	mIconList[1]->SetPosition2D(Vector2{ 0, 350 });
	mIconList[2]->SetPosition2D(Vector2{ 150, 350 });

	for (Components* componenent : mIconList[0]->GetAllComponent())
	{
		if (SpriteC* sprite = dynamic_cast<SpriteC*>(componenent))
		{
			sprite->SetTexture(Asset::GetTexture("heartDoom"));
		}
	}
	for (Components* componenent : mIconList[1]->GetAllComponent())
	{
		if (SpriteC* sprite = dynamic_cast<SpriteC*>(componenent))
		{
			sprite->SetTexture(Asset::GetTexture("heartDoom"));
		}
	}
	for (Components* componenent : mIconList[2]->GetAllComponent())
	{
		if (SpriteC* sprite = dynamic_cast<SpriteC*>(componenent))
		{
			sprite->SetTexture(Asset::GetTexture("heartDoom"));
		}
	}
}

void DoomHudA::Update()
{
}

void DoomHudA::Destroy()
{
}
