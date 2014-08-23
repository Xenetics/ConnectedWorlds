#pragma once

#include "Sprite.h"


class World : public Sprite
{
public:
	World();
	World(int levelOrder[]);
	virtual ~World();

	int GetWidth();
	int GetHeight();
	void ChangeBackground(bool isForward); //used to move forward or backward through dimensions.

	struct Camera
	{
		float xPos = 0;
		float yPos = 0;
	};

private:
	SDL_Surface* levelSurface[7];
	void InitLevels(int amount[]);
};