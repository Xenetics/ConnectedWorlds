#pragma once

#include "World.h"

class Level : public World
{
public:
	Level(int type);
	virtual ~Level();
private:
	int levelType;

};

