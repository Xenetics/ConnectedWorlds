#include "World.h"

World::~World()
{
}

void World::Draw(SDL_Renderer* rend, b2Vec2 cameraPos)
{
	levels[currentLevel]->Draw(rend, cameraPos);
}