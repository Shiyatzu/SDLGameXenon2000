#include "Spawner.h"


void Spawner::Create()
{
	//SetName("spawn");
	probRock = 40;
	probBoost = 20;
	probMine = 30;

	timeMin = 50.0f;
	timeMax = 500.0f;

	timeToNextSpawn = (float)GetEngine()->GetNextRandom((int)timeMin, (int)timeMax);
}

void Spawner::Frame()
{
	// spawn new entity:
	if (timeToNextSpawn < 0.0f)
	{
		Object *next = GetNextObject();

		// spawn:
		if (next != NULL)
		{
			stringstream ss;
			string str;
			ss << GetEngine()->GetNextID();
			ss >> str;
			GetEngine()->AttachObject("enemy" + str, next);
		}

		timeToNextSpawn = (float)GetEngine()->GetNextRandom((int)timeMin, (int)timeMax);
	}
	else
	{
		timeToNextSpawn -= GetEngine()->GetFrameTime();
	}
}

void Spawner::Destroy()
{
}


Object * Spawner::GetNextObject()
{
	Object *next = NULL;

	int random = GetEngine()->GetNextRandom(0, 100);
	if (random < probMine) next = new Mine;
	else if (random < probBoost)  next = new Boost;
	else if (random < probRock)  next = new Rock;

	return next;
}
