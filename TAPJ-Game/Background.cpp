#include "Background.h"


void Background::Create()
{
	//SetName("background");
	GetEngine()->LoadSprite("bg", "graphics/galaxy2.bmp", false);
	SetDefaultSprite("bg");
}


void Background::Frame()
{
}

void Background::Destroy()
{
}
