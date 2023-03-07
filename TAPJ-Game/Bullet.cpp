#include "Bullet.h"


void Bullet::Create()
{
	// load the image:
	//SetName("bullet");
	GetEngine()->LoadSprite("bullet", "graphics/missile.bmp", true, true, 2, 3);
	SetDefaultSprite("bullet", 0);
	

	// get a reference to the player ship:
	ship = GetEngine()->FindObject("ship");

	// set initial position:
	SetCenter(7.0f, 4.0f);
	SetPos(ship->GetPosX(), ship->GetPosY() - ship->GetCenterY());

	// the bullets are solid:
	SetIsSolid(true);
	SetRadius(25.0f);
}



void Bullet::Frame()
{
	// move upwards:
	SetPos(GetPosX(), GetPosY() - 5.0f);

	// delete the object itself if out of bounds:
	if (GetPosY() < -10.0f)
	{
		GetEngine()->ReleaseObject(GetName());
	}
}



void Bullet::Destroy()
{
	;
}

