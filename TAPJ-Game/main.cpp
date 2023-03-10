#include "..\..\TAPJ-ENGINE\TAPJ-Engine\Engine.h"
#include "Game.h"



int main(int argv, char **argc)
{
	// load and setup the engine:
	Engine engine;

	// open the window:
	engine.OpenWindow("window title", 640, 480, Engine::RENDERER_SOFTWARE);

	// attach the master game object:
	engine.AttachObject("game", new Game);

	// start the engine:
	engine.Run();

	return 0;
}