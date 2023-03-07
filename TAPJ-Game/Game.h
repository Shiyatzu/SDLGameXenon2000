#ifndef GAME_H
#define GAME_H
#include "..\..\TAPJ-ENGINE\TAPJ-Engine\Engine.h"
#include "Ship.h"
#include "Background.h"
#include "Spawner.h"

class Game : public Object
{
public:
	void Create();
	void Frame();
	void Destroy();

	float velocity;
	int score;
	int lives;

protected:
	;
private:
	;
};
#endif
