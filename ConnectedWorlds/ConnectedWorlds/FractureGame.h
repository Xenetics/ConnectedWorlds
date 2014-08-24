#pragma once

#include "Game.h"
#include "World.h"
#include "Box2D/Box2D.h"
#include "Globals.h"

#define GRAVITY_X = 0.0f
#define GRAVITY_Y = -10.0f
#define PIXEL_CONVERSION = 0.02f
// 50 pixels is a meter in box2D

class FractureGame : public Game
{
private:
	void loadAssets();
	void update(float deltaTime);
	void draw();
	void onKeyDown(Uint16 key);
	void onKeyUp(Uint16 key);
	void updateCamera();
	void init();	

public:
	//enum levelNames{ NORMAL = 1, WATER, ICE, FIRE, SPACE, STORM, DESERT, FLIPPED };
	FractureGame() : Game()
	{
		
	}
};
