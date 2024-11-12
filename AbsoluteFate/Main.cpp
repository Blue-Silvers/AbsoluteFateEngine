#include <iostream>
#include <SDL.h>
#include <glew.h>
#include "Vector2D.h"
#include "Log.h"
#include "Game.h"
#include "Pong.h"
using namespace std;

int main(int argc, char** argv) {
	Game myGame("My Pong Game", { new Pong() });
	//myGame.Init();
	return 0;
}