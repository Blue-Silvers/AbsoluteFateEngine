#include <iostream>
#include <SDL.h>
#include <glew.h>
#include "Vector2D.h"
#include "Log.h"
#include "Game.h"
#include "Pong.h"
using namespace std;

Pong* scene = new Pong();

int main(int argc, char** argv) {
	Game myGame("My Pong Game", scene);
	//myGame.Init();
	return 0;
}