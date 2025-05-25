#include "BowlingUISkinA.h"

#include "SpriteC.h"
#include "Asset.h"
#include <iostream>

void BowlingUISkinA::Start()
{
	//load texture
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Button_1.png", "Press1");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Button_2.png", "Press2");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Button_3.png", "Press3");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Button_4.png", "Press4");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Button_5.png", "Press5");
	Asset::LoadTexture(*mSceneAttached->GetRenderer(), "Resources/Button_6.png", "Press6");

	//Icon
	mIconList.push_back(new OpenGlPictureA());
	mIconList.push_back(new OpenGlPictureA());
	mIconList.push_back(new OpenGlPictureA());
	mIconList.push_back(new OpenGlPictureA());
	mIconList.push_back(new OpenGlPictureA());
	mIconList.push_back(new OpenGlPictureA());
	for (Actor* actor : mIconList)
	{
		actor->AttachScene(GetScene());
		actor->Start();
		actor->SetScale2D(Vector2{ 0.45F, 0.45F });
	}

	mIconList[0]->SetPosition2D(Vector2{ -337, 350 }); //138px between two icon
	mIconList[1]->SetPosition2D(Vector2{ -199, 350 });
	mIconList[2]->SetPosition2D(Vector2{ -63, 350 });
	mIconList[3]->SetPosition2D(Vector2{ 75, 350 });
	mIconList[4]->SetPosition2D(Vector2{ 213, 350 });
	mIconList[5]->SetPosition2D(Vector2{ 351, 350 });

	for (Components* componenent : mIconList[0]->GetAllComponent())
	{
		if (SpriteC* sprite = dynamic_cast<SpriteC*>(componenent))
		{
			sprite->SetTexture(Asset::GetTexture("Press1"));
		}
	}
	for (Components* componenent : mIconList[1]->GetAllComponent())
	{
		if (SpriteC* sprite = dynamic_cast<SpriteC*>(componenent))
		{
			sprite->SetTexture(Asset::GetTexture("Press2"));
		}
	}
	for (Components* componenent : mIconList[2]->GetAllComponent())
	{
		if (SpriteC* sprite = dynamic_cast<SpriteC*>(componenent))
		{
			sprite->SetTexture(Asset::GetTexture("Press3"));
		}
	}
	for (Components* componenent : mIconList[3]->GetAllComponent())
	{
		if (SpriteC* sprite = dynamic_cast<SpriteC*>(componenent))
		{
			sprite->SetTexture(Asset::GetTexture("Press4"));
		}
	}
	for (Components* componenent : mIconList[4]->GetAllComponent())
	{
		if (SpriteC* sprite = dynamic_cast<SpriteC*>(componenent))
		{
			sprite->SetTexture(Asset::GetTexture("Press5"));
		}
	}
	for (Components* componenent : mIconList[5]->GetAllComponent())
	{
		if (SpriteC* sprite = dynamic_cast<SpriteC*>(componenent))
		{
			sprite->SetTexture(Asset::GetTexture("Press6"));
		}
	}
}

void BowlingUISkinA::Update()
{
}

void BowlingUISkinA::Destroy()
{
	mIconList.clear();
}
