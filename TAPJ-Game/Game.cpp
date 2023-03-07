#include "Game.h"


void Game::Create()
{
	//SetName("game");
	velocity = 0.2f;
	score = 0;
	lives = 3;

	// create the background:
	GetEngine()->AttachObject("bg", new Background);

	// create a spawner (only one needed):
	GetEngine()->AttachObject("spawn", new Spawner);

	// create the player ship:
	GetEngine()->AttachObject("ship", new Ship);

}

void Game::Frame()
{
	// update the window title:
	stringstream ss;
	ss << "Score: " << score << "    Lives: " << lives;
	GetEngine()->SetWindowTitle(ss.str());
}


void Game::Destroy()
{
	;
}
