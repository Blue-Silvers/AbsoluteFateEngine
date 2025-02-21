#include "Vector2.h"
#include "Log.h"
#include "Game.h"
#include "Pong.h"
#include "Platformer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <SDL.h>
#include <glew.h>
using namespace std;

Pong* scenePong = new Pong();
Platformer* scene = new Platformer();

int main(int argc, char** argv) {
	//Game myGame("My Pong Game", scene);
	Game myGame("Absolute Fate Engine", scene);
	//myGame.Init();
	return 0;
}