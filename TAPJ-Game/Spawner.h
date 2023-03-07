#ifndef SPAWNER_H
#define SPAWNER_H
#include "..\..\TAPJ-ENGINE\TAPJ-Engine\Engine.h"
#include "Mine.h"
#include "Boost.h"
#include "Rock.h"

// this object spawns the different entities of the game
// (walls, rocks, boosts, mines):
class Spawner : public Object
{
public:
	void Create();
	void Frame();
	void Destroy();
protected:
	;
private:
	// spawn probabilities (1% to 100%):
	int probRock;
	int probBoost;
	int probMine;

	// timers (in ms):
	float timeMin;
	float timeMax;
	float timeToNextSpawn;

	Object *GetNextObject();
};
#endif