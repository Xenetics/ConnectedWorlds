#include "World.h"
#include "FractureGame.h"
#include "Globals.h"

World::World(int levelOrder[])
{
	InitLevels(levelOrder);
}


World::~World()
{
}

int World::GetWidth()
{
	return 0;
}

int World::GetHeight()
{
	return 0;
}

void World::ChangeBackground(bool isForward)
{

}

void World::InitLevels(int levelOrder[])
{
	for (int i = 0; i < sizeof(levelOrder); i++)
	{
		switch (levelOrder[i])
		{
		case NORMAL:
			//levelSurface[i] = IMG_Load(".png");
			break;
		case WATER:
			break;
		case ICE:
			break;
		case FIRE:
			break;
		case SPACE:
			break;
		case STORM:
			break;
		case DESERT:
			break;
		case FLIPPED:

		default:
			break;
		}
	}
}
