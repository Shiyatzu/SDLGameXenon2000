#ifndef SHIP_H
#define SHIP_H
#include "Bullet.h"
#include "Game.h"

class Ship : public Object
{
public:
	void Create();
	void Frame();
	void Destroy();

protected:
	;

private:
	// ship animation:
	int sprite;
	float cooldown;

	// rate of fire (in Hz):
	float rateOfFire;

	float timeToNextFire;
};
#endif