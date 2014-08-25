#pragma once

#include "Sprite.h"
#include <Box2D/Box2D.h>
#include "Level.h"
#include <vector>

using std::vector;

class World : public Sprite
{
public:
	World(){}
	World(SDL_Texture* image) : pImage_(image)
	{
		currentLevel = 0;
		levels.push_back(new Level(1, pImage_));
	}
	virtual ~World();
	void Draw(SDL_Renderer* rend, Vec2 cameraPos);
private:
	std::vector<Level*> levels;
	SDL_Texture* pImage_;
	int currentLevel;
};