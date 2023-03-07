#include "Rock.h"


void Rock::Create()
{

	//SetName("rock");
	GetEngine()->LoadSprite("rock", "graphics/SAster64.bmp", true, true, 8, 3);
	m_frameIndex = 0;
	SetDefaultSprite("rock");

	float x = (float)GetEngine()->GetNextRandom(100, 540);
	SetPos(x, GetPosY());

	SetIsSolid(true);
	SetRadius(64.0f);

	// it takes 3 bullets to destroy a mine:
	hits = 2;
}

void Rock::Frame()
{
	Game *g = (Game*)GetEngine()->FindObject("game");

	// advance animation:
	SetDefaultSprite("rock", m_frameIndex);
	m_frameIndex++;
	if (m_frameIndex > 23) m_frameIndex = 0;

	// move downwards:
	SetPos(GetPosX(), GetPosY() + (g->velocity * GetEngine()->GetFrameTime()));

	// check if out of bounds:
	if (GetPosY() > 500.0f)
	{
		GetEngine()->ReleaseObject(GetName());
	}

	// check for collisions:
	vector<Object*> collisions = GetEngine()->GetCollisions(GetName());

	for (vector<Object*>::iterator it = collisions.begin(); it != collisions.end(); it++)
	{
		string name = (*it)->GetName();

		std::cout << "objects: " << collisions.size() << "\tn:" << name << endl;

		// check for bullets:
		if (name.find("bullet") != string::npos)
		{
			// destroy the bullet:
			GetEngine()->ReleaseObject(name);

			// decrease lives:
			hits--;

			// check if the mine is destroyed:
			if (hits <= 0)
			{
				GetEngine()->ReleaseObject(GetName());

				// increase game score by 5:
				Game *game = (Game*)GetEngine()->FindObject("game");
				game->score += 5;
			}
		}
	}
}

void Rock::Destroy()
{

}