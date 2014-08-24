#include "World.h"
#include "FractureGame.h"
#include "Globals.h"

World::World(int levelOrder[], b2World* world) : pWorld_(0)
{
	pWorld_ = world;

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
		case Globals::NORMAL:
			//levelSurface[i] = IMG_Load(".png");
			break;
		case Globals::WATER:
			break;
		case Globals::ICE:
			break;
		case Globals::FIRE:
			break;
		case Globals::SPACE:
			break;
		case Globals::STORM:
			break;
		case Globals::DESERT:
			break;
		case Globals::FLIPPED:

		default:
			break;
		}
	}
}
