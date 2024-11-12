#include <iostream>
#include <SDL.h>
#include <glew.h>
#include "Vector2D.h"
#include "Log.h"
#include "Game.h"
using namespace std;

int main(int argc, char** argv) {
	Game myGame("My Pong Game");
	myGame.Init();
	return 0;
}