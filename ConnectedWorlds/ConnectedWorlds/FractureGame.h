#pragma once

#include "Game.h"
#include "World.h"

class FractureGame : public Game
{
private:
	void loadAssets();
	void update(float deltaTime);
	void draw();
	void onKeyDown(Uint16 key);
	void onKeyUp(Uint16 key);
	void updateCamera();
	

	
	

public:
	enum levelNames{ NORMAL = 1, WATER, ICE, FIRE, SPACE, STORM, DESERT, FLIPPED };
	FractureGame() : Game()
	{
		//create new world example 
		//int makeLevels[3] = { NORMAL, FIRE, ICE }; //make a temp array of size needed
		//new World(makeLevels); //creates world with levels in order specified above
	}
};
