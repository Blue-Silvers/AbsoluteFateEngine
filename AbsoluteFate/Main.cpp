#include "Game.h"
#include "ComputeShaderScene.h"

#include <iostream>
#include <fstream>
#include <string>
#include <SDL.h>
#include <glew.h>
using namespace std;

//Create your scene
ComputeShaderScene* computeShaderScene = new ComputeShaderScene();

//Choose your scene
int main(int argc, char** argv) {
	Game myGame("Compute shader", computeShaderScene, IRenderer::RendererType::OPENGL);
	return 0;
}