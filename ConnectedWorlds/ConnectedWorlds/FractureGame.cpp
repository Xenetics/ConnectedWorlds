#include "FractureGame.h"

#include <stdlib.h>
#include <ctime>
#include <iostream>
//#include <Box2D/Box2D.h>

void FractureGame::loadAssets()
{

}

void FractureGame::init()
{
	InitSDL();
	Run();
	Clean();
	//psass on world of box 2d

	//create new world example 
	//int makeLevels[3] = { NORMAL, FIRE, ICE }; //make a temp array of size needed
	//new World(makeLevels, world*); //creates world with levels in order specified above

}

void FractureGame::update(float deltaTime)
{

}

void FractureGame::onKeyDown(Uint16 key)
{
	switch (key)
	{
	case SDL_SCANCODE_ESCAPE:
		running_ = false;
		break;
	default:
		break;
	}
}

void FractureGame::onKeyUp(Uint16 key)
{
	
}

void FractureGame::draw()
{
	Game::draw();
}

void FractureGame::updateCamera()
{

}