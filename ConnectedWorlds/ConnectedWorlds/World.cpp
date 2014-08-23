#include "World.h"
#include "FractureGame.h"

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
		case FractureGame::NORMAL:
			//levelSurface[i] = IMG_Load(".png");
			break;
		case FractureGame::WATER:
			break;
		case FractureGame::ICE:
			break;
		case FractureGame::FIRE:
			break;
		case FractureGame::SPACE:
			break;
		case FractureGame::STORM:
			break;
		case FractureGame::DESERT:
			break;
		case FractureGame::FLIPPED:

		default:
			break;
		}
	}
}
