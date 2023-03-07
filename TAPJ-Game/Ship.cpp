#include "Ship.h"


void Ship::Create()
{
	//SetName("ship");
	GetEngine()->LoadSprite("ship", "graphics/Ship1.bmp", true, true, 7, 1);

	// center image:
	sprite = 3;
	SetDefaultSprite("ship", sprite);

	SetCenter(32.0f, 32.0f);
	SetPos(400.0f, 300.0f);

	rateOfFire = 10.0f;
	timeToNextFire = 1000.0f / rateOfFire;

	cooldown = 600.0f;

	// make the ship detectable for collisions:
	SetIsSolid(true);

	// set its collision radius:
	SetRadius(120.0f);
}



void Ship::Frame()
{
	// move the ship:
	if (GetEngine()->input->KeyIsPressed(Input::ARROW_LEFT))
	{
		SetPos(GetPosX() - 10.0f, GetPosY());

		// change the sprite:
		sprite--;
		if (sprite < 0) sprite = 0;
		cooldown = 600.0f;
	}

	if (GetEngine()->input->KeyIsPressed(Input::ARROW_RIGHT))
	{
		SetPos(GetPosX() + 10.0f, GetPosY());

		// change the sprite:
		sprite++;
		if (sprite > 6) sprite = 6;
		cooldown = 600.0f;
	}

	// if there was no turning lately, straignt up the ship:
	if (cooldown < 500.0f && sprite < 3) sprite++;
	if (cooldown < 200.0f && sprite < 3) sprite++;
	if (cooldown < 500.0f && sprite > 3) sprite--;
	if (cooldown < 200.0f && sprite > 3) sprite--;
	SetDefaultSprite("ship", sprite);
	cooldown -= GetEngine()->GetFrameTime();


	if (GetEngine()->input->KeyIsPressed(Input::ARROW_UP))
	{
		SetPos(GetPosX(), GetPosY() - 10.0f);
	}

	if (GetEngine()->input->KeyIsPressed(Input::ARROW_DOWN))
	{
		SetPos(GetPosX(), GetPosY() + 10.0f);
	}

	if (GetEngine()->input->KeyIsPressed(Input::SPACE))
	{
		if (timeToNextFire < 0.0f)
		{
			timeToNextFire = 1000.0f / rateOfFire;

			Bullet *b = new Bullet;

			stringstream ss;
			ss << GetEngine()->GetNextID();
			string num;
			ss >> num;

			GetEngine()->AttachObject("bullet" + num, b);
		}
		else
		{
			timeToNextFire -= GetEngine()->GetFrameTime();
		}

	}

	// check for collisions:
	vector<Object*> collisions = GetEngine()->GetCollisions(GetName());

	for (vector<Object*>::iterator it = collisions.begin(); it != collisions.end(); it++)
	{
		string name = (*it)->GetName();

		// check for mine and rock
		if (name.find("enemy") != string::npos)
		{
			// destroy the object:
			GetEngine()->ReleaseObject(name);
			
			Game *game = (Game*)GetEngine()->FindObject("game");
			game->lives -= 1;

		}
	}

	GetEngine()->Delay(10);
}



void Ship::Destroy()
{
	cout << "--ship destroyed--\n";
}
