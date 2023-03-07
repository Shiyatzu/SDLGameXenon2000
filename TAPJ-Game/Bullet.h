#ifndef BULLET_H
#define BULLET_H
#include "..\..\TAPJ-ENGINE\TAPJ-Engine\Engine.h"

class Bullet : public Object
{
public:
	void Create();
	void Frame();
	void Destroy();

protected:
	;

private:
	Object * ship;
};
#endif
