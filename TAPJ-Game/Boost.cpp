#include "Boost.h"


void Boost::Create()
{
	//SetName("boost");
	float x = (float)GetEngine()->GetNextRandom(100, 540);
	SetPos(x, GetPosY());
}


void Boost::Frame()
{
	Game *g = (Game*)GetEngine()->FindObject("game");

	// move downwards:
	SetPos(GetPosX(), GetPosY() + (g->velocity * GetEngine()->GetFrameTime()));

	// check if out of bounds:
	if (GetPosY() > 500.0f)
	{
		GetEngine()->ReleaseObject(GetName());
	}
}

void Boost::Destroy()
{
}
