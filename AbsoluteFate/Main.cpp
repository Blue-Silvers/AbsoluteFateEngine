#include <iostream>
#include <SDL.h>
#include <glew.h>
#include "Vector2D.h"
#include "Log.h"
using namespace std;

int main(int argc, char** argv) {
	Vector2D myVector = Vector2D::One;
	myVector *= 2.0f;
	Log::Info("");
	return 0;
}