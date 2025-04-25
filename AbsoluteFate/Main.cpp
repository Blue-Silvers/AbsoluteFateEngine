#include "Game.h"
#include "Pong.h"
#include "Platformer.h"
#include "GlTestScene.h"
#include "BowlingScene.h"
#include "DoomScene.h"
#include <iostream>
#include <fstream>
#include <string>
#include <SDL.h>
#include <glew.h>
using namespace std;

Pong* scenePong = new Pong();
Platformer* scene = new Platformer();
GlTestScene* sceneOpenGl = new GlTestScene();
BowlingScene* sceneBowling = new BowlingScene();
DoomScene* doomScene = new DoomScene();

int main(int argc, char** argv) {
	//Game myGame("My Pong Game", scene);
	//Game myGame("Absolute Fate Engine", scene, IRenderer::RendererType::SDL);
	//Game myGame("Absolute Fate Engine", sceneOpenGl, IRenderer::RendererType::OPENGL);
	Game myGame("Super Bowling 3D", sceneBowling, IRenderer::RendererType::OPENGL);
	//Game myGame("Doom", doomScene, IRenderer::RendererType::OPENGL);
	return 0;
}