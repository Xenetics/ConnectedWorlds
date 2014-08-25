#include "World.h"

World::~World()
{
}

void World::Draw(SDL_Renderer* rend, Vec2 cameraPos)
{
	levels[currentLevel]->Draw(rend, cameraPos);
}