#ifndef MINE_H
#define MINE_H
#include "..\..\TAPJ-ENGINE\TAPJ-Engine\Engine.h"
#include "Game.h"

class Mine : public Object
{
public:
	void Create();
	void Frame();
	void Destroy();
protected:
	;
private:
	int m_frameIndex;
	int hits;
};
#endif

