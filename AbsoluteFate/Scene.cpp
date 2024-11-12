#include "Scene.h"

Scene::Scene(std::string pTitle)
{
	mTitle = pTitle;

}

void Scene::SetRenderer(Renderer* pRenderer)
{
	mRenderer = pRenderer;
}

void Scene::Start()
{
}

void Scene::Update()
{
}

void Scene::Render()
{
	
}

void Scene::OnInput(SDL_Event)
{
}

void Scene::Close()
{
}
