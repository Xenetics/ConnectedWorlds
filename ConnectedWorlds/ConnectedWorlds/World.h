#pragma once

#include "Sprite.h"
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

	float getWidth()
	{
		return levels[currentLevel]->GetWidth();
	}
private:
	std::vector<Level*> levels;
	SDL_Texture* pImage_;
	int currentLevel;
};